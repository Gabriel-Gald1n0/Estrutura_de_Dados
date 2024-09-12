#include <stdlib.h>
#include <stdio.h>

struct l{
    int num;
    struct l *prox;
};

typedef struct l lista;

void insere(int n, lista **p);
void imprime(lista *p);
lista *concatena(lista *l1, lista *l2);


int main(void){
    lista *l1 = NULL;
    lista *l2 = NULL;
    int n = 0, m = 0, num = 0;

    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        if( 0 <= n && n <= 100){
            for(int i = 0; i < n; i++){
                scanf("%d", &num);
                insere(num,&l1);
            }
        
        scanf("%d", &m);
        if (0 <= m && m <= 100){
            for(int i = 0; i < m; i++){
                scanf("%d", &num);
                insere(num,&l2);
            }
        }

        lista *concatenada = concatena(l1,l2);
        imprime(concatenada);
        l1 = NULL;
        l2 = NULL;
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

lista *concatena(lista *l1, lista *l2){
    if(l1 == NULL){
        return l2;
    }

    lista *temp = l1;
    while(temp->prox != NULL){
        temp = temp->prox;
    }
    temp->prox = l2;
    return l1;
}