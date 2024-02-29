#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define PRINTLEN 80

int get_line(char line[], int maxline);

int main(void)
{
    char line[PRINTLEN+1];    
    int len, longline;

    longline = FALSE;
    while ((len = get_line(line, PRINTLEN+1)) > 0) {
        if (line[len-1] != '\n') {
            
            printf("%s", line);
            longline = TRUE;
        } else if (longline){
          
            printf("%s", line);
            longline = FALSE;
        }
    }
    return EXIT_SUCCESS;
}


int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
