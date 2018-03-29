#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <ctype.h>
#include "lexer.h"
#include "checker.h"

extern char *string_categoria[];

#define MATCH_PATERN(pat) strlen(t->lxme) == strlen(pat) && !strncmp(t->lxme, pat, strlen(pat)) 

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

int check_type(Token *t) {

    int i;
    char *tmp;
    regex_t prep_id, prep_number, prep_str;
 
    // printf("AQUI eh padrao %s\n", lxme_terminal[ID_ID - 1]);
    if(regcomp(&prep_id, "[:alpha:]*", REG_ICASE));
        // printf("REGEX PATT WRONG\n");
    if(regcomp(&prep_number, "[:digit:]*", REG_ICASE));
        // printf("REGEX PATT WRONG\n");
    if(regcomp(&prep_str, "[\"][:alpha:]*", REG_ICASE));

    /****
    for(i = 0; tmp = lxme_terminal[i]; i++) {
        // printf("===> Comparing ===\n%s %s\n", t->lxme, lxme_terminal[i]);
        if(strlen(t->lxme) == strlen(tmp) && !strncmp(t->lxme, tmp, strlen(tmp))) {
            t->cat = i;
            // printf("BINGO!\n");
            break;
        }
        else 
            t->cat = ID_UNKNOWN;
    }
    ****/

    if (tmp = rindex(t->lxme, '\n'))
        *tmp = '\0';

    if (MATCH_PATERN("if")) t->cat = ID_IF;
    else if (MATCH_PATERN("elif")) t->cat = ID_ELIF;
    else if (MATCH_PATERN("else")) t->cat = ID_ELSE;
    else if (MATCH_PATERN("loop")) t->cat = ID_LOOP;
    else if (MATCH_PATERN("boot")) t->cat = ID_BOOT;
    else if (MATCH_PATERN("//")) t->cat = ID_DBAR;
    else if (MATCH_PATERN("in")) t->cat = ID_IN;
    else if (MATCH_PATERN("out")) t->cat = ID_OUT;
    else if (MATCH_PATERN("write")) t->cat = ID_WRITE;
    else if (MATCH_PATERN("read")) t->cat = ID_READ;
    else if (MATCH_PATERN("step")) t->cat = ID_STEP;
    else if (MATCH_PATERN("return")) t->cat = ID_RET;
    else if (MATCH_PATERN("not")) t->cat = ID_NOT;
    else if (MATCH_PATERN("and")) t->cat = ID_AND;
    else if (MATCH_PATERN("or")) t->cat = ID_OR;
    else if (MATCH_PATERN("eq")) t->cat = ID_EQ;
    else if (MATCH_PATERN("neq")) t->cat = ID_NEQ;
    else if (MATCH_PATERN("leave")) t->cat = ID_LEAVE;
    else if (MATCH_PATERN("#")) t->cat = ID_SPECIAL;
    else if (MATCH_PATERN("numi")) t->cat = ID_NUMI;
    else if (MATCH_PATERN("numf")) t->cat = ID_NUMF;
    else if (MATCH_PATERN("str")) t->cat = ID_STR;
    else if (MATCH_PATERN("(")) t->cat = ID_APAR;
    else if (MATCH_PATERN(")")) t->cat = ID_FPAR;
    else if (MATCH_PATERN("{")) t->cat = ID_ACHAV;
    else if (MATCH_PATERN("}")) t->cat = ID_FCHAV;
    else if (MATCH_PATERN("[")) t->cat = ID_ACOL;
    else if (MATCH_PATERN("]")) t->cat = ID_FCOL;
    else if (MATCH_PATERN("+")) t->cat = ID_MAIS;
    else if (MATCH_PATERN("-")) t->cat = ID_MENOS;
    else if (MATCH_PATERN("/")) t->cat = ID_DIV;
    else if (MATCH_PATERN("*")) t->cat = ID_MULT;
    else if (MATCH_PATERN("^")) t->cat = ID_POT;
    else if (MATCH_PATERN("<")) t->cat = ID_MENQ;
    else if (MATCH_PATERN(">")) t->cat = ID_MAIQ;
    else if (MATCH_PATERN(">=")) t->cat = ID_MAIG;
    else if (MATCH_PATERN("<=")) t->cat = ID_MEIG;
    else if (MATCH_PATERN("=")) t->cat = ID_ATRIB;
    else if (MATCH_PATERN("%")) t->cat = ID_MOD;
    else if (MATCH_PATERN(",")) t->cat = ID_COMMA;
    else if (MATCH_PATERN("end")) t->cat = ID_END;
    else t->cat = ID_UNKNOWN;

    if(t->cat == ID_UNKNOWN) {
        if(!regexec(&prep_id, t->lxme, 0, NULL, 0))
            t->cat = ID_ID;
        else if(!regexec(&prep_number, t->lxme, 0, NULL, 0))
            t->cat = ID_NUM;
        else if(!regexec(&prep_str, t->lxme, 0, NULL, 0))
            t->cat = ID_STR;
        else if(!isspace(t->lxme))
            t->cat = ID_UNKNOWN;
    }
    // else if(t->cat == ID_UNKNOWN)
    //     printf("BINGO UNKNOWN!\n");


    // printf("(%04d, %10s) {%s}\n", t->cat, lxme_terminal[t->cat - 1],t->lxme);
    // printf("==> 3 eh %s\n", typename(3));
    //
    // printf("==> 2.0 eh %s\n", typename(2.0));

    return t->cat;
}


