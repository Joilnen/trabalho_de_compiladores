#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "lexer.h"

extern FILE *stream;
extern int buff_size;
extern char *analizing;
extern int l, c;

extern Token token;
extern char *lxme_terminal[];

static const char *string_categoria[] = {
    "ID_IF",    "ID_ELIF",  "ID_ELSE",    "ID_LOOP",   
    "ID_BOOT",  "ID_DBAR",  "ID_IN",      "ID_OUT",
    "ID_WRITE", "ID_READ",  "ID_STEP",    "ID_RET",
    "ID_NOT",   "ID_AND",   "ID_OR",      "ID_EQ",
    "ID_NEQ",   "ID_LEAVE", "ID_SPECIAL", "ID_NUMI",
    "ID_NUMF",  "ID_STR",
    "ID_APAR",  "ID_FPAR",  "ID_ACHAV",   "ID_FCHAV", "ID_ACOL",
    "ID_FCOL",  "ID_MAIS",  "ID_MENOS",   "ID_DIV",   "ID_MULT",
    "ID_POT",   "ID_MENQ",  "ID_MAIQ",    "ID_MAIG",  "ID_MEIG",
    "ID_ATRIB", "ID_MOD",   "ID_COMMA",   "ID_NUM",   "ID_ID",
    "ID_END",   "ID_UNKNOWN"
};

int main(int ac, char *av[])
{

    char file_name[80], opt;

    file_name[0] = '\0';

    int i;
    buff_size = 2048;


    for(i = 0; i < ac; ++i) {
        // if(strstr(av[i], ".j"))
        int a = strlen(av[i]);
        if(av[i][a-1] == 'j' && av[i][a-2] == '.')
            strcpy(file_name, av[i]);
    }


    if(!file_name[0])
        stream = fopen("test.j", "r");
    else
        stream = fopen(file_name, "r");

    if(!stream) {
        printf("\n--- jSmall Programinha ---\nno file found to analyze\nuse ./programinha file.j\n\n");
        clean_memory();
        return -1;
    }

    analizing = malloc(buff_size);

    while(fgets(analizing, buff_size, stream)) {

        c = 1;
        token.lxme = malloc(strlen(analizing) * sizeof(char));
        Token *t = NULL;

        /* Empilha todos tokens  pra analise */
        while(t = nextToken())
            printf("[%03d,%03d] (%04d, %10s) {%s}\n", t->line, t->column, t->cat, string_categoria[t->cat], t->lxme);

        free(token.lxme);
        // printf("\n");
    }

    clean_memory();

    static_assert(1, "Falha tenebrosa");

    return 0;
}


