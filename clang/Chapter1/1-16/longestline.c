#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 3   

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;           
    int max;           
    int prevlen;       
    char line[MAXLINE];     
    char longest[MAXLINE];  
    char temp[MAXLINE];    

    max = prevlen = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (prevlen + len > max) {
            max = prevlen + len;
            if (!prevlen)
                copy(longest, line);
            else
                copy(longest, temp);
        }
        if (line[len-1] != '\n') {
            if (!prevlen) 
                copy(temp, line);
            prevlen += len;
        } else
            prevlen = 0;
    }
    if (max > 0) {   
        printf("%s", longest);
        if (longest[max-1] != '\n')
            putchar('\n');
        printf("%d characters\n", max);
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


void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
