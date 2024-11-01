#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int valor;
    struct TNo *dir;
    struct TNo *esq;
}No;

void push(No **l, int n);
void print(No *l, int v);

int main(){
    No *arv = NULL;
    int N = 0, V = 0, K = 0;
    int valor = 0;

    while (1){
       scanf("%d",&N);

        if(N == -1) break;

        for(int i = 0; i < N; i++){
            scanf("%d", &K);
            for(int j = 0; j < K; j++){
                scanf("%d",&valor);
                push(&arv,valor);
            }
            scanf("%d",&V);
            printf("\n");
            print(arv,V);
            arv = NULL;
        }
    }
    return 0;
}

void push(No **l, int n){
    if(*l == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = n;
        novo->dir = NULL;
        novo->esq = NULL;
        *l = novo;
    } else {
        if(n > (*l)->valor)
            push(&(*l)->dir,n);
        else
            push(&(*l)->esq,n);
    }
}

void print(No *l, int v){
    if(l != NULL){
        if(v == l->valor){
            printf("%d [", v);
            int first = 1;
            if(l->esq != NULL){
                printf("%d", l->esq->valor);
                first = 0;
            }
            if(l->dir != NULL){
                if (!first) printf(", ");
                printf("%d", l->dir->valor);
            }
            printf("]\n");
        }else {
            print(l->esq, v);
            print(l->dir, v);
        }        
    }
}