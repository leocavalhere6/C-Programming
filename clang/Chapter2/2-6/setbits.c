#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
    printf("%u\n", setbits(170, 4, 3, 7));
    return EXIT_SUCCESS;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    int i, mask, j;
    i = (x >> (y+1-n)) & ~(~0 << n);
    mask = ~(((1 << n)-1) << (p+1-n));
    j = mask & x;
    return j | i << (p+1-n);
}

