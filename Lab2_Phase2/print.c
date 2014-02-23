/* Nash Kleppan
 * Vishal Mehta
 * Patrick O Connor
 * CSE 230
 * Spring 2014 ASU */
#include "common.h"
#include <stdio.h>
#include <stlib.h>
#include <sting.h>

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        /* Missing Code Here */
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        save_chp = line + MAX_PRINT_LINE_LENGTH;
        save_ch = *save_chp;
        *save_chp = '\0';
    }
    if (save_chp)
    {
        printf("%s", line);
        *save_chp = save_ch;
    }
    /* Missing Code Here */
    if (save_chp)
    {
        /* Missing Code Here */
    }
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 1;
    char string= {"Page\t"};
    char name[]=source_name;
    char tab[]= {"\t"};
    char the_date=date;
    
    //Print header. IE: "Page    1  /Users/bholto/Downloads/NEWTON.P  Tue Feb 18 20:56:59 2014"
    //-NK
    printf("%s",string);
    printf("%d", page_number);
    printf("%s\t", name);
    printf("%s\t",the_date);
    printf("%s\n", "");
    printf("%s\n", "");
}
