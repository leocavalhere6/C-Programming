#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a char\n");
    printf("getchar() != EOF : %d\n", getchar() != EOF);
    return EXIT_SUCCESS;
}
