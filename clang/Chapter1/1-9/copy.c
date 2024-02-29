#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    int c, prevblank;

    prevblank = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (prevblank == FALSE) {
                putchar(c);
                prevblank = TRUE;
            }
        }
        if (c != ' ') {
            putchar(c);
            prevblank = FALSE;
        }
    }
    return EXIT_SUCCESS;
}
