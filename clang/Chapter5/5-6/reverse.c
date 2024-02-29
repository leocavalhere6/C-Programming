#include <string.h>

void reverse(char *s)
{
    char tmp, *p;
    p = s + strlen(s) - 1;
    while (p > s) {
        tmp = *s;
        *s++ = *p;
        *p-- = tmp;
    }
}
