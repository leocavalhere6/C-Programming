#include <stdio.h>
#include <stdlib.h>

int strend(const char *s, const char *t)
{
    int ls, lt;
    
    for (ls = 0; *(s+ls); ++ls);  
    for (lt = 0; *(t+lt); ++lt);   
    if (ls >= lt) {         
        s += ls - lt;      
        while (*s++ == *t++)
            if (!*s)       
                return 1;   
    }
    return 0;
}

int main(void)
{
    char s[100] = "abcdef\0xyz";
    char t[100] = "def\0klm";
    printf("%d\n", strend(s, t));
    return EXIT_SUCCESS;
}
