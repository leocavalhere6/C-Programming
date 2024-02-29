#include <stdio.h>
#include <stdlib.h>

#define PROGRAM 0
#define COMMENT 1
#define QUOTE   2
#define SLASH   3
#define STAR    4
#define LITERAL 5

int main(void)
{
    int c, state;
    char quote;

    state = PROGRAM;
    while ((c = getchar()) != EOF) {
        if (state == PROGRAM) {
            
            if (c == '/')
                state = SLASH;
            else {
                if (c == '"' || c == '\'') {
                    state = QUOTE;
                    quote = c;
                }
                putchar(c);
            }
        } else if (state == COMMENT) {
            if (c == '*')
                state = STAR;
        } else if (state == QUOTE) {
            if (c == '\\')
                state = LITERAL;
            else if (c == quote)
                state = PROGRAM;
            putchar(c);
        } else if (state == SLASH) {
            if (c == '*')
                state = COMMENT;
            else if (c == '"' || c == '\'') {
                state = QUOTE;
                quote = c;
            } else {
                state = PROGRAM;
                putchar('/');
                putchar(c);
            }
        } else if (state == STAR) {
            if (c == '/')
                state = PROGRAM;
            else if (state != '*')
                state = COMMENT;
        } else if (state == LITERAL) {
            putchar(c);
            state = QUOTE;
        }
    }
    return EXIT_SUCCESS;
}

