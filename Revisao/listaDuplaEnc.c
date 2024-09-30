#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant;
}No;

void push(No **l, int n){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = *l;
    novo->ant = NULL;
    if(*l != NULL)
        (*l)->ant = novo;
    *l = novo;
}

void pushF(No **l, int n){
     No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = NULL;
    novo->ant = NULL;

    if(*l == NULL){
        *l = novo;
    } else{
        No *aux = *l;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
}

void pop(No **l, int n){
    No *novo = (No*)malloc(sizeof(No));
    No *aux = *l;
    if(*l == NULL)
        printf("Vazio\n");
    if(aux->valor == n){
        *l = aux->prox;
        if(*l != NULL)
            (*l)->ant = NULL;
        free(aux); 
    }else{
        while(aux->prox != NULL && aux->prox->valor != n)
            aux = aux->prox;
        if(aux->prox != NULL){
            novo = aux->prox;
            aux->prox = novo->prox;
            novo->ant = aux;
            if(aux->prox != NULL)
                aux->prox->ant = aux;
            free(novo);
        }else
            printf("Numero nao encontrado\n");
    }
}

void pop2(No **l){
    No *novo = NULL;
    novo = *l;
    *l = (*l)->prox;
    if(*l != NULL)
        (*l)->ant = NULL;
    free(novo);
}

void printC(No *l){
    while(l != NULL){
        printf("%d\n",l->valor);
        l = l->prox;
    }
    printf("\n");
}

void printD(No *l){
    while(l->prox != NULL){
        l = l->prox;
    }
    while(l != NULL){
        printf("%d\n",l->valor);
        l = l->ant;
    }
    printf("\n");
}

int main()
{
    No *lista = NULL;
    int V[] = {1,2,3};
    for(int i = 0; i < 3; i++)
        push(&lista, V[i]);

    printC(lista);
    pop(&lista, 3);
    printC(lista);
    pop2(&lista);
    printC(lista);

    printf("Crescente\n");
    printC(lista);
    printf("Decrescente\n");
    printD(lista);

    pushF(&lista, 10);
    printC(lista);
    return 0;
}