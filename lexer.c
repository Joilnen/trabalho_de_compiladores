/********************************
 * Trabalho Analisador Lexico   *
 * Aluno: Joilnen Batista Leite *
 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <ctype.h>
#include "lexer.h"
#include "parser.h"
#include "checker.h"

FILE *stream = NULL;
char *line_buffer = NULL;
int buff_size;
char *analizing = NULL;
int l = 1 , c = 1;
Token token;

/****
const char *lxme_terminal[] = {
    "if",   "elif",   "else", "loop", "boot",
    "//",   "in",     "out",  "write","read",
    "step", "return", "not",  "and", "or",
    "eq", "neq", "leave", "#", "numi",
    "numf", "str",
    "(", ")",
    "{", "}", "[", "]",
    "+", "-", "/", "*", "^",
    "<", ">", ">=", "<=",
    "=", "%", ","
    "[0-9]*",
    "^[a-zA-Z_][0-9]*", "%END", "%UNKNOWN"
};
****/

/*** Lexer functions ***/
static char* consome() {

    char *ptA = NULL;
    char *ptB = NULL;

    if(!analizing)
        return NULL;

    ptA = ptB = analizing;

    while(*ptA == ' ' || *ptA == '\t' || *ptA == '\r') {
        ++ptA;
        ++c;
        ptB = ptA;
    }

    if(*ptA == '~') {
        ptA++;
        while(*ptA != '~') {
            ++ptA;
            ++c;
        }
        analizing = ptB = ptA;
    }

    token.column = c;

    while(*(ptB + 1) != ' ' && *(ptB + 1) != ',' && *(ptB + 1) != '(' && *(ptB + 1) != '[' &&
          *(ptB + 1) != ')' && *(ptB + 1) != ']') {
        if(*ptB == '\n') {
            token.line = l;
            ++l;
            c = 1;
            break;
        }
        ++ptB;
        ++c;
    }
    ++c;

    if(*ptA == '(' || *ptA == '[')
        ptB = ptA;
    else if(*ptA == '"') {
        if(*(ptA + 1) == '"') {
            ptB = ptA + 2;
            goto RET;
        }
        while(*ptB != '"' && *ptB != EOF && *ptB != '\n')
            ++ptB;
        if(*ptB != '"') 
            return NULL;
    }

RET:
    strncpy(token.lxme, ptA, (ptB + 1) - ptA);
    *(token.lxme + (ptB + 1 - ptA)) = '\0';

    analizing = ++ptB;
    // token.line = l;
    if(token.lxme)
        check_type(&token);

    return token.lxme;
}

Token *nextToken() {

    char *tmp = NULL;
    if(!strlen(analizing))
        return NULL;

    // printf("%d %s", l,  analizing);
    token.line = l;
    token.cat = ID_UNKNOWN;

    tmp = consome();

    if(tmp = rindex(token.lxme, '\n'))
        *tmp = '\0';

    /* check_terminal_regex(tmp, strlen(tmp)); */

    // Only a test of _Generic 
    // printf("==> 3 eh %s\n", typename(3));
    // printf("==> 2.0 eh %s\n", typename(2.0));

    return &token;
}

void clean_memory() {
    if(line_buffer)
        free(line_buffer);
    if(stream) 
        fclose(stream);
    stream = NULL;
    line_buffer = NULL;
}


