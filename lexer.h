#ifndef LEXER_H_
#define LEXER_H_
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

//Token_kind
typedef enum {
    TOKEN_END,
    TOKEN_INVALID,
    TOKEN_SYMBOL,
    TOKEN_NUM,

} Token_Kind;

const char *token_kind_name(Token_Kind kind) {
    switch (kind) {
    case TOKEN_END:
        return "TOKEN_END";
    case TOKEN_INVALID:
        return "TOKEN_INVALID";
    case TOKEN_SYMBOL:
        return "TOKEN_SYMBOL";
    case TOKEN_NUM:
        return "TOKEN_NUM";
    default:
        return "ERROR";
    }
    return NULL;
};

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

bool is_num(char l){
    if (isdigit(l) == 1){
        return true;
    }
    return false;
}

Token lexer_next(Lexer *l) {
    Token token = {
        .text = &l->content[l->cursor],
    };

    if (l->content[l->cursor] == '+') {
        l->cursor += 1;
        token.kind = TOKEN_SYMBOL;
        token.text_len = 1;
        return token;
    }
    if (isalpha(l->content[l->cursor])){
        l->cursor += 1;
        token.kind = TOKEN_INVALID;
        return token;

    }
    if (is_num((l->content[l->cursor]))){
        l->cursor += 1;
        token.kind = TOKEN_NUM;
        return token;
    }
    l->cursor +=1;

    return token;
}





#endif // LEXER_H_
