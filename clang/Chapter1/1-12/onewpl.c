#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    int c, prevblank;

    prevblank = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (prevblank == FALSE)
                putchar('\n');
            prevblank = TRUE;
        } else {
            prevblank = FALSE;
            putchar(c);
        }
    }
    return EXIT_SUCCESS;
}

