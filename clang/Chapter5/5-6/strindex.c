int strindex(const char *s, const char *t)
{
    const char *i, *j, *k;

    for (i = s; *i != '\0'; i++) {    
        j = i, k = t;
        while(*k != '\0' && *j++ == *k++);
        if (k-t > 0 && *k == '\0')   
            return i-s;                 
    }
    return -1;                    
}
