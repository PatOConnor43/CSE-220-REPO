/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */

#include "common.h"
#include <stdio.h>
#include <time.h>
#include "print.c"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
	//print p;
    
   /* Missing Code Here */
	//I finished Init_Listener I think. This should set date and set the file pointer -PO
	init_lister(argv[0], source_name, date);
	//Working on getting the print_page_header to work here -PO
	print_page_header(argv[0], date);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
	
    
    /* Missing Code Here */
	//Associates the file pointer with a generic input file -PO,NK
	file = fopen(source_file_name, "r");


	//This section of code sets the date and time. -PO
	timer = time(NULL);
	dte = ctime(&timer);
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 1;
    
    if (fgets(source_buffer,MAX_SOURCE_LINE_LENGTH,src_file) !=Null) //If a source line is found, return true. -NK
    {
	
        //Format line for printing. -NK
	sprintf(print_buffer,"$d: %s",line_number,source_buffer);
	//Send formatted line to print_line -NK
	print_line(print_buffer,src_name,todays_date)
	line_number++; //Increment for next line. -NK
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

