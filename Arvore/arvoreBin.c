#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int valor;
    struct TNo *dir;
    struct TNo *esq;
}No;

void push(No **l,int v){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = v;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*l == NULL)
        *l = novo;
    else{
        No *aux = *l;
        No *ant = NULL;

        while(aux != NULL){
            ant = aux;
            if(v > aux->valor)
                aux = aux->dir;
            else
                aux = aux->esq;
        }

        if(v > ant->valor)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
}

No *pushRecursivo(No *l,int v){
    if(l == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = v;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if(v > l->valor)
        l->dir = pushRecursivo(l->dir,v);
    else
        l->esq = pushRecursivo(l->esq,v);

    return l;
}

void pushRecVoid(No **l,int v){
    if(*l == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = v;
        novo->dir = NULL;
        novo->esq = NULL;
        *l = novo;
    }else{
        if(v > (*l)->valor)
            pushEficiente(&(*l)->dir,v);
        else
            pushEficiente(&(*l)->esq,v);
    }
}

void pushEficiente(No **l, int n){
    No *aux = *l;
    while(aux != NULL){
        if(n > aux->valor)
            l = &aux->dir;
        else
            l = &aux->esq;
        aux = *l;
    }
    aux = (No*)malloc(sizeof(No));
    aux->valor = n;
    aux->dir = NULL;
    aux->esq = NULL;
    *l = aux;
}

void printPreOrdem(No *l){
    if(l != NULL){
        printf("%d\n",l->valor);
        print(l->esq);
        print(l->dir);
    }
}

void printEmOrdem(No *l){
    if(l != NULL){
        print(l->esq);
        printf("%d\n",l->valor);
        print(l->dir);
    }
}

void printPosOrdem(No *l){
    if(l != NULL){
        print(l->esq);
        print(l->dir);
        printf("%d\n",l->valor);
    }
}

int main(){
    No *raiz = NULL;
    int N = 0;
    int valor = 0;

    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&valor);
        push(&raiz,valor);
    }

    printf("\n");
    printPreOrdem(raiz);

    return 0;
}