#include <stdio.h>
#include <stdlib.h>

#define NUMCHARS 128 

int main(void)
{
    int c, chars[NUMCHARS];

    for (c = 0; c < NUMCHARS; ++c)
        chars[c] = 0;

    while ((c = getchar()) != EOF)
        chars[c] += 1;


    for (c = 0; c < NUMCHARS; ++c) {
        if (chars[c] > 0) {
            if (c == '\b')        
                printf("\\b");
            else if (c == '\n')     
                printf("\\n");
            else if (c == '\t')    
                printf("\\t)");
            else                    
                printf("%2c", c);
            
            printf(" (%3d): %3d\n", c, chars[c]);
        }
    }
    return EXIT_SUCCESS;
}
