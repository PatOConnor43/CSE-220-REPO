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
    
   /* Missing Code Here */
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    //Open FILE -NK
    file=fopen(source_file_name,"r"); //Open source file
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    
    if (fgets(source_buffer,MAX_SOURCE_LINE_LENGTH,src_file) !=Null) //If a source line is found, return true. -NK
    {
	//To be continued
	line_number++;//increment line number
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

