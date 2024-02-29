#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]);
int validrange(char c1, char c2);

int main(void)
{
    char s1[512] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);
    
    return EXIT_SUCCESS;
}

void expand(char s1[], char s2[])
{
    int i, j;
    char tmp;
    int dash;

    dash = 0;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '-') {
            if (i == 0 || s1[i+1] == '\0') {
                s2[j++] = s1[i];
            } else {
                if (validrange(s1[i-1], s1[i+1])) {
                    while (s2[j-1] < s1[i+1]) {
                        s2[j] = s2[j-1] + 1;
                        j++;
                    }
                    ++i;
                } else {
                    s2[j++] = s1[i];
                }
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int validrange(char c1, char c2)
{
    if (('a' <= c1 && c1 <= 'z') && 
        (c1  <= c2 && c2 <= 'z'))
        return TRUE;
    if (('A' <= c1 && c1 <= 'Z') && 
        (c1  <= c2 && c2 <= 'Z'))
        return TRUE;
    if (('0' <= c1 && c1 <= '9') && 
        (c1  <= c2 && c2 <= '9'))
        return TRUE;
    
    return FALSE; 
}
