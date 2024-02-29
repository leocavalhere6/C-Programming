#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        if (c == '\b')
            printf("\\b");
        if (c == '\\')
            printf("\\\\");
        else
            printf("%c", c);
    }
    return EXIT_SUCCESS;
}
