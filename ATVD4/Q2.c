#include <stdlib.h>
#include <stdio.h>

struct l{
    int num;
    struct l *prox;
};

typedef struct l lista;

void insere(int n, lista **p);
void imprime(lista *p);
lista* retira_n(lista *l, int n);
void libera(lista *l) ;

int main(void){
    lista *l1 = NULL;
    int n = 0, num = 0;

    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        if( 0 <= n && n <= 100){
            for(int i = 0; i < n; i++){
                scanf("%d", &num);
                insere(num,&l1);
            }
        imprime(l1);

        scanf("%d", &num);
        lista *l1_removido = retira_n(l1,num);
        if(l1_removido)
            imprime(l1_removido);
        else
            printf("Lista Vazia\n");
        l1_removido = NULL;
        l1 = NULL;
        }
    }
}

void insere(int n, lista **p){
    lista *nova = (lista*) malloc(sizeof(lista));

    if(nova != NULL){
        nova->num = n;
        nova->prox = NULL;
    }
    
    lista *temp = *p;
    if(*p == NULL)
        *p = nova;
    else{
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = nova;
    }
}

void imprime(lista *p){
    lista* novo = p;
    while(novo != NULL){
        printf("%d->", novo->num);
        novo = novo->prox;
    }
    printf("NULL\n");
}

lista* retira_n(lista *l, int n){
    lista *aux = NULL, *remover = NULL, *temp = l;

    // Remove os valor n no inicio da lista
    while( temp != NULL && temp->num == n){
        remover = temp;
        temp = temp->prox;
        free(remover);
    }

    if(temp == NULL)
        return NULL;

    // Atualiza o início da lista
    l = temp;
    aux = temp;
    // Percorre o restante da lista e remove n
    while(aux->prox != NULL){
        if(aux->prox->num == n){
            remover = aux->prox;
            aux->prox = remover->prox;
            free(remover);
        }else{
            aux = aux->prox;
        }
    }   
    return l;
}

