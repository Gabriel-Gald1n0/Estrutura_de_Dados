// Questao 1
#ifndef BIBLIOTECA1_H
#define BIBLIOTECA1_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct expressao {
    char descricao[81];
    struct expressao *prox, *ant;
};

typedef struct expressao Expressao;
void consultar(Expressao **ex, char *palavra, int maxCap, int *size);
void imprimeCrescente(Expressao *ini);
void imprimeDecrescente(Expressao *ini);
void historico(Expressao *lista, int n);
void libera(Expressao **ini);
int cont(Expressao *ini, char *palavra);



#endif
