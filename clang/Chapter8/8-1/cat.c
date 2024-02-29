#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);
    char *prog = argv[0]; 

    if (argc == 1) 
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
    exit(EXIT_SUCCESS);
}

void filecopy(int ifd, int ofd)
{
    char buf[BUFSIZ];
    int c;

    while ((c = read(ifd, buf, BUFSIZ)) > 0) 
        write (ofd, buf, c);         
}
