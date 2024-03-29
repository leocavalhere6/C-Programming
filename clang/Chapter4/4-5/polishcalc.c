#include <stdio.h>
#include <stdlib.h>
#include <string.h>     
#include <math.h>       

#define MAXOP   100     
#define NUMBER  '0'     
#define LIBFUNC '1'     

void dofunc(char []);
int getop(char []);
void push(double);
double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case LIBFUNC:
            dofunc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero devisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}


void dofunc(char s[])
{
    double op1, op2;
    if (strcmp(s, "sin") == 0)          
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)     
        push(cos(pop()));
    else if (strcmp(s, "tan") == 0)     
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)     
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {   
        op2 = pop();
        op1 = pop();
        if (op1 == 0 && op2 <= 0)
             printf("error: domain (%g^%g)\n", op1, op2);
        else
            push(pow(pop(), op2));
    } else {
        printf("error: unknown command %s\n", s);
    }
}

#define MAXVAL  100 

int sp = 0;         
double val[MAXVAL];  


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}



double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);


int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return LIBFUNC;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;                      
    if (isdigit(c) || c == '-')     
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')                   
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';                      
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
