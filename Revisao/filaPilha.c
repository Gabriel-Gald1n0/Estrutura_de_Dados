#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No; // Fila

typedef struct no Pilha;

void pushP(Pilha **l, int n){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));

    novo->valor = n;
    novo->prox = *l;
    *l = novo;
}

void pushF(No **l, int n){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = NULL;
    if(*l == NULL){
        novo->prox = *l;
        *l = novo;
    }else{
        No *aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void inverte(No **l){
    Pilha *p = NULL;
    No *aux = *l;

    while(aux != NULL){
        pushP(&p,aux->valor);
        aux = aux->prox;
    }

    free(aux);

    while(p != NULL){
        pushF(&aux, p->valor);
        p = p->prox;
    }
    *l = aux;
    free(p);
}

void print(No *l){
    printf("Lista:\n");
    while (l != NULL){
        printf("%d\n",l->valor);
        l = l->prox;
    }
    printf("\n");
}

int main(){
    No *lista = NULL;
    int v[] = {1,2,3,5,4};

    for(int i = 0; i < 5; i++)
        pushF(&lista, v[i]);

    print(lista);
    inverte(&lista);
    printf("Lista Invertida:\n");
    print(lista);
}