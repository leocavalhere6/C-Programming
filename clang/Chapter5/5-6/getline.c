#include <stdio.h>

int getline(char *s, int lim)
{
    char c, *p;
    
    p = s; 
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}
