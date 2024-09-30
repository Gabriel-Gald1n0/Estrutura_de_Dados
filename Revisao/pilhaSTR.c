#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor;
    struct no *prox;
} No;

void push(No **l, char n){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = *l;
    *l = novo;
}


char pop(No **l){
    No *novo = (No*)malloc(sizeof(No));

    if(*l == NULL){
        return '\0';
    }

    novo = *l;
    *l = (*l)->prox;
    char c = novo->valor;
    free(novo);
    return c;
}

void print(No *l){
    int cont = 0;
    if( l == NULL){
        printf("Pilha vazia\n");
        return;
    }
         
    printf("Pilha\n");
    while(l != NULL){
        printf("Valor[%d]: %c\n", cont, l->valor);
        cont++;
        l = l->prox;
    }
    printf("\n");
}

void topo(No *l){
    if( l == NULL){
        printf("Pilha vazia\n");
        return;   
    }
         
    printf("Topo: %c\n", l->valor);
}

No *concatena(No *l1, No *l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    No *aux = l2;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = l1;

    return l2;
}

int verifica(char *str){
    int n = strlen(str);
    No *l = NULL;
    int i = 0;
    if(n%2 != 0) return 0;

    for(; i < n/2; i++)
        push(&l,str[i]);
    
    for(i = n/2; i < n; i++)
        if(str[i] != pop(&l))
            return 0;
    
    return 1;
}

void inverte(char *c){
    No *l = NULL;
    int i = 0;

    if(c[strlen(c) - 1] != '.'){
        printf("Texto invalido\n");
        return;
    }

    while(c[i] != '\0'){
        if(c[i] != ' ' && c[i] != '.')
            push(&l,c[i]);
        else{
            while(l != NULL)
                printf("%c",pop(&l));
            printf("%c",c[i]);
        }
        i++;
    }
}

int main(){
    No *lista = NULL;
    int v = 0;
    char c[] = "ABCCBA";
    char str[] = "ESTE EXERCICIO E MUITO FACIL.";
    v = strlen(c);
    for(int i = 0; i < v/2; i++)
        push(&lista,c[i]);

    printf("%s\n",str);
    inverte(str);
    printf("\n\n");

    if(verifica(c)){
        printf("Formato XY: %s\n",c);
    } else
        printf("Fora do formato padrao\n");

    print(lista);
    return 0;
}