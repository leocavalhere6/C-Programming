#include <stdlib.h>  
#include "reverse.c"

void itoa(int n, char *s)
{
    int sign;
    char *p;
    
    p = s;
    sign = n;
    do {       
        *p++ = abs(n % 10) + '0';  
    } while (n /= 10);             
    if (sign < 0)
        *p++ = '-';
    *p = '\0';
    reverse(s);
}
