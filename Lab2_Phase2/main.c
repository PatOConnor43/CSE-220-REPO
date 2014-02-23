/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */

#include "common.h"
#include <stdio.h>
#include <time.h>

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    
   /* Missing Code Here */
	//Using the init_lister. Currently only prints date and time -PO
	init_lister(argv[1], source_name, date);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
	
    
    /* Missing Code Here */
	//Trying to create a newfile with the name of the second input -PO
	file = fopen(name, "w");
	fprintf(file, "Testing...\n");


	//This section of code is just used to print date and time. -PO
	timer = time(NULL);
	printf(ctime(&timer));
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    
    if (1) //This is missing a condition
    {
		/*  Missing Code Here */
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

