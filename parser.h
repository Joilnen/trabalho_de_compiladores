#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

/*** Syntaxer functions ***/
typedef struct Symbol {
    char *terminal;
    char *n_terminal;
} Symbol;

typedef struct GrammarExpr {
    Symbol line, column;
    Symbol *expr;
} GrammarExpr;

typedef struct TableSyntax {
    GrammarExpr *cel;
} TableSyntax;

typedef struct Stack {
    void *value;
    struct Stack *next, *prev;
} Stack;

#endif

