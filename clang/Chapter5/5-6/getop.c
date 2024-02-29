#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'  

int getch(void);
void ungetch(int);


int getop(char *s)
{
    char c;
    
    while ((*s = c = getch()) == ' ' || c == '\t');
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;     
    --s;               
    if (isdigit(c))     
        while (isdigit(*++s = c = getch()));
    if (c == '.')    
        while (isdigit(*++s = c = getch()));
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;      

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
