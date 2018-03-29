#ifndef TABLE_H
#define TABLE_H

#define NTERM_ID_SIZE 16
#define LXME_SIZE 24
#define LXME_AND_EXTRA_SIZE 18

const char *table[NTERM_ID_SIZE][LXME_SIZE] = {
 /* "if"      "elif"     "else"   "loop"   "boot", "//",  "in", "out", "write", "read", "step", "return", "and", "or", "not", "eq", "neq", "leave", "#",      "mumi", "numf", "str", "=",  lxme_extra */

    "IdExpr", "IdExpr",  NULL,    "IdExpr", NULL,   NULL , NULL, NULL,  NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL, NULL,  /* IdDecis_1"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,   NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdDecis_2"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* CLoop"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdRet"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdEnd"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* opAr"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* opAr"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* opLog"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdRel"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdDig"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdCar"*/

    "IdRel.IdId",     NULL,       NULL,    NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,     NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdExpr"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdExpU"*/

    NULL,     NULL,      "IdStm", NULL,    NULL , NULL, NULL,   NULL,   NULL,   NULL,   NULL,     NULL,  NULL,  NULL, NULL, NULL,  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL,  /* IdId"*/

 "IdDecis_1", "IdDecis_1","IdDecis_2", "CLoop",    NULL , "IdEnd", NULL,   NULL,   NULL,   NULL,  "CLoop", "IdRet",  "OpLog",  "OpLog", "OpLog", "OpRel",  NULL ,   "IdExpr", NULL,   NULL,    NULL, NULL  /* IdStm"*/
};


#endif
