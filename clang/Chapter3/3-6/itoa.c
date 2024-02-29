#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
    int n = INT_MIN;
    char s[16];

    itoa(1337, s, 8);
    printf("%s\n", s);
    itoa(n, s, 16);
    printf("%s\n", s);
    
    return EXIT_SUCCESS;
}


void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n;
    i = 0;
    do {       
        s[i++] = abs(n % 10) + '0';    
    } while (n /= 10);                

    if (sign < 0)
        s[i++] = '-';
    while (i < w)   
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}


void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
