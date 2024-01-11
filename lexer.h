#ifndef LEXER_H_
#define LEXER_H_

#include <stddef.h>

//Token_kind
typedef enum {
    TOKEN_END,
    TOKEN_INVALID,
    TOKEN_PLUS,

} Token_Kind;

typedef char *token_kind_name(Token_Kind kind);

// Token
typedef struct {
    Token_Kind kind;
    const char *text;
    size_t text_len;


} Token;


// Lexer
typedef struct {
    const char *content;
    size_t content_len;
    size_t cursor;
    size_t line;
    size_t bol;
} Lexer;

Lexer lexer_new(const char *content, size_t content_len){
    Lexer l = {0};
    l.content = content;
    l.content_len = content_len;
    return l;

};



Token lexer_next(Lexer *l) {
    Token token = {
        .text = &l->content[l->cursor],
    };

    if (l->content[l->cursor] == '+') {
        l->cursor += 1;
        token.kind = TOKEN_PLUS;
        token.text_len = 1;
        return token;
    }

    l->cursor +=1;

    return token;
}





#endif // LEXER_H_
