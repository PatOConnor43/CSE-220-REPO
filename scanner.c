/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */
//  scanner.c
//  Lab3
//
//  Created by Bryce Holton.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include <stdio.h>
#include "scanner.h"
#include "common.h"


static Token* get_word(char* input_token_ptr);
static Token* get_number(char* input_token_ptr);
static Token* get_special(char* input_string);
static char* downshift_word(char* string_to_downshift);
static BOOLEAN is_reserved_word(char* string_to_check);

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE
}
CharCode;

/*********************
 Static Variables for Scanner
 Must be initialized in the init_scanner function.
 *********************/
static FILE *src_file;
static char src_name[MAX_FILE_NAME_LENGTH];
static char todays_date[DATE_STRING_LENGTH];
static CharCode char_table[256];  // The character table

typedef struct
{
    char *string;
    TokenCode token_code;
}
RwStruct;

const RwStruct rw_table[9][10] = {
    {{"do",DO},{"if",IF},{"in",IN},{"of",OF},{"or",OR},{"to",TO},{NULL,0}}, //Reserved words of size 2
    {{"and",AND},{"div",DIV},{"end",END},{"for",FOR},{"mod",MOD},{"nil",NIL},{"not",NOT},{"set",SET},{"var",VAR},{NULL,0}}, //Reserved words of size 3
    {{"case",CASE},{"else",ELSE},{"file",FFILE},{"goto",GOTO},{"then",THEN},{"type",TYPE},{"with",WITH},{NULL,0}}, //Reserved words of size 4
    {{"array",ARRAY},{"begin",BEGIN},{"const",CONST},{"label",LABEL},{"until",UNTIL},{"while",WHILE},{NULL,0}},  //Reserved words of size 5
    {{"downto",DOWNTO}, {"packed",PACKED},{"record",RECORD}, {"repeat",REPEAT},{NULL,0}},  // Reserved words of size 6
    {{"program", PROGRAM},{NULL,0}}, // Reserved words of size 7
    {{"function", FUNCTION},{NULL,0}}, // Reserved words of size 8
    {{"procedure", PROCEDURE},{NULL,0}}  // Reserved words of size 9
};

void init_scanner(FILE *source_file, char source_name[], char date[])
{
    src_file = source_file;
    strcpy(src_name, source_name);
    strcpy(todays_date, date);
    
    	int i; //initialize character table
	for(i = 0; i < 265; ++i)
	{
		if(i <= 32 || i == 127)
			char_table[i] = EOF_CODE;
		else if(i == 39)
			char_table[i] = QUOTE;
		else if (i >= 48 && i <= 57)
			char_table[i] = DIGIT;
		else if ((i >= 65 && i <= 90) || (i >= 97 && i <=122))
			char_table[i] = LETTER;
		else
			char_table[i] = SPECIAL;

	}//end loop
    
}

//get next line from file and store in source_buffer
//prints next line

int line_number = 0;
BOOLEAN get_source_line(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
//    char source_buffer[MAX_SOURCE_LINE_LENGTH];  //I've moved this to a function parameter.  Why did I do that?
    
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
       sprintf(print_buffer, "%4d: %s", ++line_number, source_buffer);
       
        print_line(print_buffer, src_name, todays_date);
	
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}


//declare counter to 0 in every get function
//update pointer in get_token()
/*** AT THE END OF WHILE LOOP
if counter == length -1
	call token_ptr = strtok(NULL, " "); 
else
	&token_ptr = token_ptr[counter + 1]


*****/
int counter = 0; 
Token* get_token()
{
    char token_string[MAX_TOKEN_STRING_LENGTH]; //Store your token here as you build it.

    Token* token_return = NULL;  //value to be returned
	    
	if(get_source_line(token_string)) //next line is stored in token_string
	{
		char *token_ptr = strtok(token_string, " ");//tokenize to point to first non-space character
		puts(token_ptr);
		//build linked list
		while(token_ptr != NULL) 
		{
			//check the first character of string
			int x = (int) token_ptr[0];
			int length = strlen(token_ptr);

			if(char_table[x] == LETTER)
			{
				puts("LETTER has been selected");
				puts(token_ptr);
				add_token_to_list(token_return, get_word(token_ptr)); //store to token_return
				puts(token_ptr);
				
				//UPDATE POINTER
				if(counter >= length) //check counter >= length  GO TO NEXT WORD
				{
					puts(token_ptr);
					token_ptr = strtok(NULL, " ");
					puts(token_ptr);
				}
				else
				{
					token_ptr = &token_ptr[counter];
				}
				
			}
			else if(char_table[x] == DIGIT)
			{
				puts("DIGIT has been selected");
				add_token_to_list(token_return, get_number(token_ptr));
				
				//UPDATE POINTER
				if(counter == length) //check counter >= length  GO TO NEXT WORD
				{
					token_ptr = strtok(NULL, " ");
				}
				else
				{
					token_ptr = &token_ptr[counter];
				}
				
				
			}
			else if(char_table[x] == SPECIAL)
			{
				puts("SPECIAL has been selected");
				add_token_to_list(token_return, get_special(token_ptr)); //store to token_return
				
				
				//UPDATE POINTER
				if(counter == length) //check counter >= length  GO TO NEXT WORD
				{
					token_ptr = strtok(NULL, " ");
				}
				else
				{
					token_ptr = &token_ptr[counter];
				}
			}
			else if(char_table[x] == QUOTE)
			{
				puts("QUOTE has been selected"); //PRINT
				Token tmp ;
				tmp.token_code = STRING;
				tmp.next = NULL; 
				
				char tmp_string[20];
				
				BOOLEAN found = FALSE;
				int j = 1;
				int length = strlen(token_ptr);
				
				
				for(; j < length; ++j)
				{
					if((int)token_ptr[j] == 39)
					{
						found = TRUE;
						break;
					}
					else
						tmp_string[j-1] = token_ptr[j];
				}

				
				if(found == TRUE)
				{
					token_ptr = &token_ptr[j+1]; //UPDATE POINTER 
				}
				else
				{
					counter = 0;
					while(!found)
					{
						sprintf(tmp_string, "%s%s", tmp_string, " ");
						token_ptr = strtok(NULL, " ");
					
						length = strlen(token_ptr);
						int i = 0;
						for(; i < length; ++i)
						{
							if((int)token_ptr[i] == 39)
							{
								found = TRUE;
								counter = i + 1;
								break;
							}
							else
								sprintf(tmp_string, "%s%c", tmp_string, token_ptr[i]);
						}
						token_ptr = &token_ptr[counter];  //UPDATE POINTER
					}
				}
				
				
				tmp.literal_value = tmp_string;
				
				add_token_to_list(token_return, tmp);
				
				
				print_token(&tmp);

			}
			else //char_table[x] = EOF_CODE 
			{
				puts("EOF has been selected");
				token_ptr = NULL;
			}
			
			

		} //end while loop			

	} //end if statement
	return token_return;
}// end function


static Token* get_word(char* input_token_ptr)
{
 	Token tok;
 	Token* return_token = &tok;
 	counter = 0;
 	int i = 0;
 	char temp[MAX_PRINT_LINE_LENGTH];
 	int length = strlen(input_token_ptr);
 	while(char_table[input_token_ptr[counter]] == LETTER)
 	{
 		temp[counter] = input_token_ptr[counter];
 		++counter;
 	}
 	temp[counter] = '\0';
 	length = strlen(temp);
 	for(i = 0; i < strlen(temp); ++i)
 	{
 		temp[i] = tolower(temp[i]);
 	}
 	tok.literal_value = temp;
 	if(is_reserved_word(temp))
 	{
 		for(i = 0; rw_table[length-2][i].token_code != NO_TOKEN; ++i)
		{
			
			if(strcmp((rw_table[length-2][i]).string, temp) == 0)
			{
				tok.token_code = rw_table[length-2][i].token_code;
				
			}
		}
 	}
 	else
 		tok.token_code = IDENTIFIER;
 	tok.next = NULL;
 	printf("%d\n", counter);
 	
 	return return_token;
}

static Token* get_number(char* input_token_ptr)
{
    /*
     Write some code to Extract the number and convert it to a literal number.
     */
	counter = 0;
	Token tok;
	Token* return_tok = &tok;
	char temp[10];
	while(char_table[input_token_ptr[counter]] == DIGIT || input_token_ptr[counter] == '-' || input_token_ptr[counter] == 'e'){
		temp[counter] = input_token_ptr[counter];
		printf("%c\n", temp[counter]);
		++counter;
	}
		
	return_tok->literal_value = temp;
	return_tok->token_code = NUMBER;
	return_tok->next = NULL;
	return return_tok;
	
	
}



static Token* get_special(char *input_string)
{
    /*
     Write some code to Extract the special token.  Most are single-character
     some are double-character.  Set the token appropriately.
     */
     	counter = 0;
	Token *token_return;
	char val = input_string[0];
	char tmp[]= {val,'\0'};
	token_return->literal_value = tmp;
	token_return->token_code = NO_TOKEN;
	token_return->next = NULL;
	++counter;
	

	return token_return;

}

//WORKS
static char* downshift_word(char* string_to_downshift)
{
    /*
     Make all of the characters in the incoming word lower case.
     */
	int length = strlen(string_to_downshift);
	//printf("%i\n", length);
	int i;
	for(i = 0; i<length; ++i)
	{
		string_to_downshift[i] = tolower(string_to_downshift[i]); //cast a char?
	
	}
   	return string_to_downshift;
}

//WORKS
static BOOLEAN is_reserved_word(char* string_to_check)
{
     /*
     Examine the reserved word table and determine if the function input is a reserved word.
     */
	
	int length = strlen(string_to_check);
	int i = 0;
	for(i = 0; rw_table[length-2][i].token_code != NO_TOKEN; ++i)
	{
		if(strcmp(rw_table[length-2][i].string, string_to_check) == 0)
		{
			return TRUE;
		}
				
	}
	return FALSE;
    
}
