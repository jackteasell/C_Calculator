#include <stdio.h>
#include "lexer.h"
#include "string.h"


int main() {

    const char *content = "1+";
    Lexer l = lexer_new(content , strlen(content));
    Token t1 = lexer_next(&l);
    Token t2 = lexer_next(&l);
    Token t3 = lexer_next(&l);
    Token t4 = lexer_next(&l);


    printf("The Length is: %d\n", (int)l.content_len);
    printf("The Token Type is: %s\n", token_kind_name(t1.kind));
    printf("The Token Type is: %s\n", token_kind_name(t2.kind));
    printf("The Token Type is: %s\n", token_kind_name(t3.kind));
    printf("The Token Type is: %s\n", token_kind_name(t4.kind));
    return 0;
}
