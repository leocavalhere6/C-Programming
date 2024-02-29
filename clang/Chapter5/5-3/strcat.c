#include <stdio.h>
#include <stdlib.h>

void strcat(char *s, const char *t)
{
    while (*s)    
        s++;
    while (*t)      
        *s++ = *t++;
    *s = '\0';
}

int main(void)
{
    char s[100] = "ab\0c";
    char t[100] = "def";
    strcat(s, t);
    puts(s);
    return EXIT_SUCCESS;
}
