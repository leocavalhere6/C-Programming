void strncpy(char *s, const char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}
