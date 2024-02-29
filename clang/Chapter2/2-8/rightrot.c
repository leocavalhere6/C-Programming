#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, unsigned n);

int main(void)
{
    printf("%u\n", rightrot(3, 1));
    return EXIT_SUCCESS;
}


unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) {
        if(x & 1)  
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = x >> 1;
        --n;
    }
    return x;
}

