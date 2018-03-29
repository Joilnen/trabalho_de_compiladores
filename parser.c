/*********************************
 * Trabalho Analisador Sintatico *
 * Aluno: Joilnen Batista Leite  *
 * Tecnia: Preditivo Tabular     *
 *********************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "lexer.h"
#include "parser.h"
#include "table.h"

/** declared in lexer.c **/
extern FILE *stream;
extern char *line_buffer;
extern int buff_size;
extern char *analizing;
extern int l, c;

extern Token token;
extern char *lxme_terminal[];
// /**************************/

typedef struct _TokenParam {
    char *lexval;
    int column, line;
    int type;
} TokenParam;

const char *n_term_id[] = {
    "IdDecis_1", "IdDecis_2", "IdType", "CLoop",
    "IdRet", "IdEnd", "OpAr", "OpLog", "OpRel",
    "IdDig", "IdCar", "IdExpr", "IdExpU", "IdId",
    "IdStm"
};

enum {NONE, PULA_TOKEN, VOLTA_TOKEN};

struct _table {
    unsigned int idTab;
    char *ruleStr;
    struct _table *next;
} 
*table_1 = NULL;

int add_rule(char *r) {

    struct _table *t = table_1, *n;

    if(t)
        t = t->next;
    else {
        table_1 = malloc(sizeof(struct _table));
        t = table_1;
    }

    n = t;
    n->idTab++;
    n->ruleStr = malloc(sizeof(char) * strlen(r) + 1);
    strcpy(n->ruleStr, r);

    n->next = NULL;

    return 0;
}

#define MAP(A,B,R) alloc_map(A,B,R)

Stack *create_stack(void *first) {
    Stack *s = malloc(sizeof(Stack));
    s->value = first;
    s->next = NULL;
    return s;
}

void push(Stack *s, void *value) {

    Stack *t = NULL;

    do t = s; while(s = s->next);

    if(t) {
        t->next = malloc(sizeof(Stack));
        t->next->value = value;
        t->next->next = NULL;
    }
    else {
        s->next = malloc(sizeof(Stack));
        s->next->value = value;
        s->next->next = NULL;
    }
}

void *pop(Stack *s) {

    Stack *t = NULL;
    void *tmp;

    do t = s; while(s = s->next);

    if(t) {
       tmp = t->value;
        t = NULL;
    }
    else {
        tmp =  s->value;
        s = NULL;
    }
    return tmp;
}

static int syntaxer(Stack *S) {

    if(S) {

        Token *t = pop(S);
        printf("INSIDE %s %s\n", __FUNCTION__, t->lxme);

        /* procura terminal na linha da tabela q sao lxme_terminal e lxme_extra */
        int i = 0;
        for(; lxme_terminal[i]; i++) {
            printf("stacked ===>>> %s\n", lxme_terminal[i]);
            if(strcmp(t->lxme, lxme_terminal[i]))
                printf("IGUAIS\n");
        }

        int c = i;
        for(i = 0; i < NTERM_ID_SIZE; i++)
            printf("In table ==>> %s\n", table[i][c]);

    }
    return VOLTA_TOKEN;
}

static void pula_token_stack() {

}


static void volta_token_stack(TokenParam p) {
    printf("Olha isso %d %d %s\n", p.column, p.line, p.lexval);
}

int main(int ac, char *av[])
{
    enum {NONE, HELP, LEXONLY, PARSE, GUI};
    char file_name[80], opt;
    file_name[0] = '\0';
    int i;
    buff_size = 2048;
    char flag_opt = 0;

    while((opt = getopt(ac, av, "hlag")) != -1) {
        switch(opt) {
            case 'l':
                flag_opt = LEXONLY;
            break;
            case 'a':
                flag_opt = PARSE;
            break;
            case 'g':
                flag_opt = GUI;
            break;
            case 'h':
                flag_opt = HELP;
        }
    }

    for(i = 0; i < ac; ++i) {
        // if(strstr(av[i], ".j"))
        if(av[i][strlen(av[i])-2] = 'j' && av[i][strlen(av[i])-3], '.')
            strcpy(file_name, av[i]);
    }

    line_buffer = malloc(buff_size);
    analizing = malloc(buff_size);

    if(!file_name[0])
        stream = fopen("test.j", "r");
    else
        stream = fopen(file_name, "r");

    if(!stream) {
        printf("\n--- jSmall Parse ---\nno file found to analyze\nuse ./parse file.j\n\n");
        clean_memory();
        return -1;
    }

    if(flag_opt == HELP) {
        printf("parse [options] [file.j]\n"
               "      [options]:\n"
               "          -l : lexer only\n\n");
    }
    else {

        while(fgets(analizing, buff_size, stream)) {

            c = 1;
            token.lxme = malloc(strlen(analizing) * sizeof(char));
            Token *t = NULL;
            Stack *S = NULL;

            /* Empilha todos tokens  pra analise */
            while(t = nextToken())  {
                if(flag_opt != LEXONLY) {
                    if(S)
                        push(S, (Token *)t);
                    else
                        S = create_stack((Token *)t);
                }
            }

            /* Analisa tokens empilhados */
            switch(syntaxer(S)) {

            }

            free(token.lxme);
            printf("\n");
        }
    }

    clean_memory();

    static_assert(1, "Falha tenebrosa");

    return 0;
}


