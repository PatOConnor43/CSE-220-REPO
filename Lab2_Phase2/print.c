/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */
#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print,date_to_print);
	line_count = 1;
    }
	else
	{
		fputs(line, stdout);
	}
}


static void print_page_header(char source_name[], char date[])
{
    static int page_number = 1;
    char *string = {"Page\t"};
    char *name = {source_name};
    time_t timer = time(NULL);
    strncpy(date, ctime(&timer), DATE_STRING_LENGTH);
    char location[256];
    getcwd(location,sizeof(location));
    
    //Print header. IE: "Page    1  /Users/bholto/Downloads/NEWTON.PAS  Tue Feb 18 20:56:59 2014"
    //-NK
    printf("%s",string);
    printf("%d\t", page_number);
    printf("%s%s%s\t", location,"/", name);
    printf("%s\t",date);
    printf("%s\n", "");
    printf("%s\n", "");
    ++page_number;
}
