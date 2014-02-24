/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */

#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];

	source_file = init_lister(argv[1], source_name, date);
	while(get_source_line(source_file, source_name,date))
	{
		//Nothing to add
	}
	fclose(source_file);
    return 0;
}


/***
copy, open file, set date & time
***/
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;

   //source_name (source_file_name) = name (argv[1]);
	int length = strlen(name);
	strncpy(source_file_name, name, length); //source_name = argv[1]

	//Associates the file pointer with our input file -PO
	file = fopen(name, "r");


	//This section of code sets the date and time. -PO
	timer = time(NULL);
	dte = ctime(&timer);
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH]; //next line 
    static int line_number = 0;

    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL) //check if next is not null
    {	
	//need source_name = src_name;	
	
	//need sprintf
	int x =sprintf(print_buffer, "%d:\t%s", line_number, source_buffer);
	//need print_line
	print_line(print_buffer, src_name , todays_date);
	++line_number;
        return (TRUE); // Reads and Prints a line
    }

    else
    {
        return (FALSE);
    }
}
