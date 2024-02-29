#include "syscalls.h"
#include <stdlib.h>


int _fillbuf(FILE *fp)
{
    int bufsize;
    
    if (fp->flags.read == 1 && fp->flags.eof == 0 && fp->flags.err == 0)
        return EOF;
    bufsize = (fp->flags.unbuf == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL)   
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;     
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flags.eof = 1;
        else
            fp->flags.err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
