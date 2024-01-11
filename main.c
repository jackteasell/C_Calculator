#include <stdio.h>
#include "lexer.h"
#include "string.h"





int main() {

    const char *content = "1+1";
    Lexer l = lexer_new(content , strlen(content));
    Token t1 = lexer_next(&l);
    Token t2 = lexer_next(&l);
    Token t3 = lexer_next(&l);


    printf("The Length is: %d\n", (int)l.content_len);
    printf("The Token Type is: %d\n", t1.kind);
    printf("The Token Type is: %d\n", t2.kind);
    printf("The Token Type is: %d\n", t3.kind);
    return 0;
}
