#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[64];
    itob(-255, s, 8);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

void itob(int n, char s[], int b)
{
    int i, sign;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    if (2 > b || b > strlen(symbols) )
        return;    
    
    sign = n;
    i = 0;
    do {           
        s[i++] = symbols[abs(n % b)];
    } while (n /= b);                
    if (sign < 0)
        s[i++] = '-';
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

