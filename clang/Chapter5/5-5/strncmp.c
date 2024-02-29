int strncmp(char *s, const char *t, int n)
{
    for (; *s == *t && n-- > 0; s++, t++)
        if (*s == '\0' || n == 0)
            return 0;
    return *s - *t;
}
