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


	//I finished Init_Listener I think. This should set date and set the file pointer -PO
	source_file = init_lister(argv[1], source_name, date);
	//Working on getting the print_page_header to work here -PO
	//print_page_header(argv[1], date);

	
	char* source_string;
	int length = strlen(argv[1]);
	char source_string_array[length];
	strncpy(source_name, argv[1], length);
	
	//print:print_page_header(source_name, date);

	while(get_source_line(source_file, source_name,date))
	{
		//Nothing to add
	}
    return 0;
}



FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;

   //source_name = name;



	//Associates the file pointer with our input file -PO
	file = fopen("NEWTON.PAS", "r");


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
    
    if (++line_number > MAX_LINES_PER_PAGE && fgets(src_name, line_number, src_file) != NULL) //check if next is not null
    {
	source_buffer[line_number] =  *fgets(src_name, line_number, src_file); 
	//call sprintf to print source line w/ line number to print_buffer (returns int)
	print_line(print_buffer, src_name , todays_date);
        return (TRUE); // Reads and Prints a line
    }
    else
    {
        return (FALSE);
    }
}
