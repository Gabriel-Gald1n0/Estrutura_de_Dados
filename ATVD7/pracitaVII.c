#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void push(No **l, int n);
No *copy(No *l);
void reoder(No **l);

int main(){
    No *fila = NULL;
    int N = 0, M = 0, P = 0;

    while(1){
        scanf("%d", &N);
        if(N == -1) break;
        if(N > 0){
            for(int j = 0; j < N; j++){
                scanf("%d",&M);
                if(1 <= M && M <= 1000){
                    for(int i = 0; i < M; i++){
                        scanf("%d", &P);
                        if(1 <= P && P <= 1000)
                            push(&fila, P);
                    }
                    reoder(&fila);
                    fila = NULL;
            } else
                printf("Digite um numero (1 <= M <= 1000) \n");
            }
        } else
            printf("Digite um numero > 0\n");
    }
    return 0;
}

void push(No **l, int n){
    No *novo =  (No*)malloc(sizeof(No));
    novo->valor = n;
    novo->prox = NULL;

    if(*l == NULL)
        *l = novo;
    else{
        No *aux = *l;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

No *copy(No *l){
    No *aux = l;
    No *copy = NULL;

    while(aux != NULL){
        push(&copy, aux->valor);
        aux = aux->prox;
    }
    return copy;
}

void reoder(No **l){
    No *i, *j;
    No *ant = copy(*l);
    int cont = 0;

    for(i = *l; i != NULL; i = i->prox){
        for(j = i->prox; j != NULL; j = j->prox){
            if(j->valor > i->valor){
                int temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
    No *aux = *l;
    while(ant != NULL && aux != NULL){
        if(ant->valor == aux->valor)
            cont++;
        ant = ant->prox;
        aux = aux->prox;
    }

   printf("%d\n", cont);

}