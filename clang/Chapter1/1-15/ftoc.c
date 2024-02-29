#include <stdio.h>
#include <stdlib.h>

float ftoc(float f);

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   
    upper = 300;  
    step = 20;    

    printf("  F    C  \n");
    printf("----------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return EXIT_SUCCESS;
}


float ftoc(float f)
{
    float c;
    c = (5.0/9.0) * (f-32.0);
    return c;
}
