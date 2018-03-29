#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

/*** Lexer structures ***/
enum TOKEN_CAT {
    ID_IF,     ID_ELIF,  ID_ELSE,    ID_LOOP,   
    ID_BOOT,   ID_DBAR,  ID_IN,      ID_OUT,
    ID_WRITE,  ID_READ,  ID_STEP,    ID_RET,
    ID_NOT,    ID_AND,   ID_OR,      ID_EQ,
    ID_NEQ,    ID_LEAVE, ID_SPECIAL, ID_NUMI,
    ID_NUMF,   ID_STR,
    ID_APAR,   ID_FPAR,  ID_ACHAV,   ID_FCHAV, ID_ACOL,
    ID_FCOL,   ID_MAIS,  ID_MENOS,   ID_DIV,   ID_MULT,
    ID_POT,    ID_MENQ,  ID_MAIQ,    ID_MAIG,  ID_MEIG,
    ID_ATRIB,  ID_MOD,   ID_COMMA,   ID_NUM,   ID_ID,
    ID_END,    ID_UNKNOWN
};

typedef struct Token {
    int id;
    char *lxme;
    enum TOKEN_CAT cat;
    unsigned int line, column;
    char t:1;
    union {
        char c;
        short s;
        int i;
        float f;
        double d;
    } lxval;
} Token;

Token *nextToken();
void clean_memory();

#endif


