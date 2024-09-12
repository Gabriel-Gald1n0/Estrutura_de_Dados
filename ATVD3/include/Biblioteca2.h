// Questao 2
#ifndef BIBLIOTECA2_H
#define BIBLIOTECA2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LIMITE_NOME 30
#define LIMITE_TELEFONE 10

typedef struct {
    char nome[LIMITE_NOME + 1];
    char telefone[LIMITE_TELEFONE];
    char email[30];
} contato;


void addContatos(contato **agenda,  int *cont);
void printContatos(contato *agenda, int cont);
void searchContatos(contato *agenda, int cont);
void deleteContato(contato *agenda, int *cont);


#endif
