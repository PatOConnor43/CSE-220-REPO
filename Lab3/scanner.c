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

/*******************
 Static functions needed for the scanner
 You need to design the proper parameter list and 
 return types for functions with ???.
 ******************/
static ??? get_char(???);
static ??? skip_comment(???);
static ??? skip_blanks(???);
static ??? get_word(???);
static ??? get_number(???);
static ??? get_string(???);
static ??? get_special(???);
static ??? downshift_word(???);
static BOOLEAN is_reserved_word(???);

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE,
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
	for(i = 0; i > 265; ++i)
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
    /*******************
     initialize character table, this table is useful for identifying what type of character 
     we are looking at by setting our array up to be a copy the ascii table.  Since C thinks of 
     a char as like an int you can use ch in get_token as an index into the table.
     *******************/
    
}
BOOLEAN get_source_line(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
//    char source_buffer[MAX_SOURCE_LINE_LENGTH];  //I've moved this to a function parameter.  Why did I do that?
    static int line_number = 0;
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print_line(print_buffer, src_name, todays_date);
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
Token* get_token()
{
    char ch; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH]; //Store your token here as you build it.
    char *token_ptr = token_string[0]; //write some code to point this to the beginning of token_string
    Token* token_return;  //I am missing the most important variable in the function, what is it?  Hint: what should I return?
    
    //1.  Skip past all of the blanks
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    //3.  Call the appropriate function to deal with the cases in 2.
    
    return ???; //What should be returned here?
}
static char get_char(string_to_check[])
{
	
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
     */
	char temp_char;
    
    /*
     Write some code to set the character ch to the next character in the buffer
     */
}
static char* skip_blanks(char string_that_needs_skipping[])
{
    /*
     Write some code to skip past the blanks in the program and return a pointer
     to the first non blank character
     */
	int i = 0;	//index of string_that_needs_skipping
	int j = 0;	//index of ptr
	char* ptr = (char*)malloc(sizeof(char));
	ptr[0] = '\0';
	while(string_that_needs_skipping[i] != '\0'){
		if(string_that_needs_skipping[i] != ' '){
			ptr[j] = string_that_needs_skipping[i];
			++j;
		}
		++i;
	}
	return ptr;
	free(ptr);
    
}
static char* skip_comment(char string_that_needs_skipping[])
{
    /*
     Write some code to skip past the comments in the program and return a pointer
     to the first non blank character.  Watch out for the EOF character.
     */
	int i = 0;	//index of string_that_needs_skipping
	int j = 0;	//index of ptr
	char* ptr = (char*)malloc(sizeof(char));
	while(string_that_needs_skipping[i] != '\0'){
		if(string_that_needs_skipping[i] != '{'){
			ptr[j] = string_that_needs_skipping[i];
			++j;
		}
		if(string_that_needs_skipping[i] == '{'){
			while(string_that_needs_skipping[i] != '}'){
				++i;
			}
			if(string_that_needs_skipping[i] == '}'){
				ptr[j] = string_that_needs_skipping[++i];
				j++;
			}
		}
		++i;
	}

	return ptr;
	free(ptr);
}
static ??? get_word(???)
{
    /*
     Write some code to Extract the word
     */
    
    //Downshift the word, to make it lower case
    
    /*
     Write some code to Check if the word is a reserved word.
     if it is not a reserved word its an identifier.
     */
}
static ??? get_number(???)
{
    /*
     Write some code to Extract the number and convert it to a literal number.
     */
}
static ??? get_string(???)
{
    /*
     Write some code to Extract the string
     */
}
static ??? get_special(???)
{
    /*
     Write some code to Extract the special token.  Most are single-character
     some are double-character.  Set the token appropriately.
     */
}
static char* downshift_word(char string_to_downshift[])
{
    /*
     Make all of the characters in the incoming word lower case.
     */
	int length = strlen(string_to_downshift);
	printf("%i\n", length);
	int i;
	for(i = 0; i<length; ++i){
	string_to_downshift[i] = tolower(string_to_downshift[i]);
	
	}
   	return string_to_downshift;
}
static BOOLEAN is_reserved_word(???)
{
    /*
     Examine the reserved word table and determine if the function input is a reserved word.
     */
    return FALSE;
}