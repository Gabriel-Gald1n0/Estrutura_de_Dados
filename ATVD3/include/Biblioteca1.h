// Questao 1
#ifndef BIBLIOTECA1_H
#define BIBLIOTECA1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int inicio;
  int fim;
} intervalo;


void addIntervalo(intervalo **intervalos, int *tamanho);
void verificarIntervalo(intervalo *intervalos, int tamanho);


#endif
