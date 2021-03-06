/* Nash Kleppan
* Vishal Mehta
* Patrick O Connor
* CSE 230
* Spring 2014 ASU */
// main.c
// Lab3
//
// Created by Bryce Holton.
// Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "print.h"
#include "scanner.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[])
{
    Token l;
    Token *token = (Token*)malloc(sizeof(Token));
    Token *token_list = &l; //This needs to be implemented as a linked list in scanner.h.
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    init_scanner(source_file, source_name, date);
    
    do
    {
        token = get_token();
        //add_token_to_list(token_list, token);
        
    }
    while (token_list->next != NULL);//What is the sentinal value that ends this loop?
    
    quit_scanner(source_file, token_list);
    free(token); //Deallocate memory
    return 0;
}
void add_token_to_list(Token *list, Token *new_token)
{
    // Add new_token to the list knowing that list is a linked list.
static int iterations = 0;
    //puts(new_token->literal_value);
//puts("zzzzzzzzzHHHHAAALLLOOO");

if(iterations == 0)
{
//puts("HHHHAAALLLOOO");
list->literal_value = new_token->literal_value;
list->token_code = new_token->token_code;
list->next = NULL;

print_token(list);

}
else
{
//puts("WHAT UP");
// while(list->next != NULL)
//{
//puts("IT WENT THROUGH WHILE");
//printf("%s\n", new_token->literal_value);
//printf("%s\n", list->literal_value);
list->next = new_token;
//list->literal_value = new_token->literal_value;
//list->token_code = new_token->token_code;
//list->next = NULL;
print_token(new_token);
//puts(list->literal_value);
//}
//list->next = new_token;
//puts("Made it through while loop");
}
++iterations;
//puts("SUCCESS");
}
void quit_scanner(FILE *src_file, Token *list)
{
    //write code to free all of the memory for the token list
    Token *temp;
    temp= list;
    while(temp->next != NULL) //free ALL of the linked list.
    {
      temp=list;
      list=list->next;
      free(temp);
    }
      
    fclose(src_file);
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    
    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}
