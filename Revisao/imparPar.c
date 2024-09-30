/*
Escreva um programa que leia um número indefinido de valores inteiros, encerrando a entrada
de dados ao encontrar o valor zero (0). Para cada número lido, determine se ele é par ou ímpar.
Se o número for par, insira-o na FILA PAR; caso contrário, insira-o na FILA ÍMPAR. Após
finalizar a entrada de dados, retire elementos de cada fila alternativamente, começando pela
FILA ÍMPAR, até que ambas as filas estejam vazias. Se o elemento retirado de uma das filas
for positivo, adicione-o a uma PILHA; caso contrário, remova um elemento da PILHA. Por fim,
exiba o conteúdo da PILHA.
*/
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

int pop(No **l){
    No *novo = (No*)malloc(sizeof(No));
    novo = *l;
    *l = (*l)->prox;
    int v = novo->valor;
    free(novo);
    return v;
}

void popP(No **l){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    if(*l == NULL){
        return;
    }
        
    novo = *l;
    *l = (*l)->prox;
    free(novo);
}


void print(No *l){
    if(l == NULL){
        printf("Lista vazia\n");
        return;
    }

    printf("Lista:\n");
    while (l != NULL){
        printf("%d\n",l->valor);
        l = l->prox;
    }
    printf("\n");
}

int isVazia(No **l){
    if(*l != NULL)
        return 0;
    return 1;
}

int main(){
    No *par = NULL, *impar = NULL;
    Pilha *p = NULL;
    int v;
    int op = -1;
    int cont = 0;

    while(op != 0){
        scanf("%d", &op);
        if(op == 0) break;
        if(op%2 == 0)
            pushF(&par,op);
        else 
            pushF(&impar,op);
        cont++;
    }
    printf("IMPAR\n");
    print(impar);
    printf("\n");
    printf("PAR\n");
    print(par);  
    printf("\n");

    if(!isVazia(&impar)){
    cont--;
    v = pop(&impar);
    if(v > 0) pushP(&p, v);
    else popP(&p);
    }

    for(int i = 0; i < cont; i++){
        if(i%2 == 0){
            if(!isVazia(&par)){
                v = pop(&par);
                if(v > 0) pushP(&p, v);
                else popP(&p);
            } else break;
        }else{
            if(!isVazia(&impar)){
                v = pop(&impar);
                if(v > 0) pushP(&p, v);
                else popP(&p);
            } else break;
        }
    }
    printf("PILHA\n");
    print(p);
}