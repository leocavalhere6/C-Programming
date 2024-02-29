#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "abcdef";
    char s2[] = "bdf";
    squeeze(s1, s2);
    printf("%s\n", s1);

    return EXIT_SUCCESS;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int instr2;

    for (i = j = 0; s1[i] != '\0'; i++) {
        instr2 = FALSE;
        for (k = 0; s2[k] != '\0' && !instr2; k++)
            if (s2[k] == s1[i])
                instr2 = TRUE;
        if (!instr2)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
