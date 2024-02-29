void strcat(char *s, const char *t, int n)
{
    while (*s)             
        s++;
    while (*t && n-- > 0)  
        *s++ = *t++;
    *s = '\0';
}
