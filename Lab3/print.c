/* Nash Kleppan
* Vishal Mehta
* Patrick O Connor
* CSE 230
* Spring 2014 ASU */
// print.c
// Lab3
//
// Created by Bryce Holton.
// Copyright (c) 2014 Bryce Holton. All rights reserved.
//
#include <stdlib.h>
#include "print.h"
#include "scanner.h"

const char* const SYMBOL_STRINGS[] =
{
    "<no token>", "<IDENTIFIER>", "<NUMBER>", "<STRING>",
    "^","*","(",")","-","+","=","[","]",":",";",
    "<",">",",",".","/",":=","<=",">=","<>","..",
    "<END OF FILE>", "<ERROR>",
    "AND","ARRAY","BEGIN","CASE","CONST","DIV","DO","DOWNTO",
    "ELSE","END","FILE","FOR","FUNCTION","GOTO","IF","IN",
    "LABEL","MOD","NIL","NOT","OF","OR","PACKED","PROCEDURE",
    "PROGRAM","RECORD","REPEAT","SET","THEN","TO","TYPE","UNTIL",
    "VAR","WHILE","WITH",
};

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print, date_to_print);
        line_count = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH)
    {
        save_chp = &line[MAX_PRINT_LINE_LENGTH];
    }
    if (save_chp)
    {
        save_ch = *save_chp;
        *save_chp = '\0';
    }
    printf("%s", line);
    if (save_chp)
    {
        *save_chp = save_ch;
    }
}


static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    char location[256];
    getcwd(location,sizeof(location));
    putchar(FORM_FEED_CHAR);
    printf("Page %d %s %s\n\n", ++page_number, location, date);
}


void print_token(Token *token)
{
    //Missing code goes here
  char* concatenate_string[MAX_PRINT_LINE_LENGTH];// = (char*)malloc(sizeof(char));
  char* start = " >> ";

  if(token != NULL )
  {
    if(token->token_code == NO_TOKEN) //SPECIAL CHARACTERS
    {
      sprintf((char*)concatenate_string, "%1s%18s", token->literal_value, token->literal_value);
    }
    if(token->token_code == NUMBER )
    {
      sprintf((char*)concatenate_string, "%1s%18s", SYMBOL_STRINGS[NUMBER], token->literal_value);
    }
    else // if it is a word
    {
      if(token->token_code >= AND && token->token_code <= WITH) //if it is a reserved word
      {	
      char upperCase[strlen(token->literal_value)];//= (char*) malloc(sizeof(char));
      int i;
      for(i = 0; i < strlen(token->literal_value); ++i)
      {
	upperCase[i] = toupper(token->literal_value[i]);
      }
      upperCase[strlen(token->literal_value)] = '\0';
      sprintf((char*)concatenate_string, "%s%1s\t\t%s",start, upperCase, token->literal_value);
      }
      else //non-reserved word
      {
	sprintf((char*)concatenate_string, "%s%1s\t%s", start, SYMBOL_STRINGS[token->token_code], token->literal_value);
      }
    }	
      puts((char*)concatenate_string); //print stuff
      token = token->next; //go to next word
    }//end while
}//end print_token
