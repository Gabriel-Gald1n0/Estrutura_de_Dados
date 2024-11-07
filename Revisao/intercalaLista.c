#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

void push(No **l, int n){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = *l;
    *l = novo;
}

void pop(No **l){
    No *novo = (No*)malloc(sizeof(No));

    if(*l == NULL){
        printf("Pilha vazia\n");
        return;
    }

    novo = *l;
    *l = (*l)->prox;
    free(novo);
}

void print(No *l){
    int cont = 0;
    if( l == NULL){
        printf("Pilha vazia\n");
        return;
    }
         
    printf("Pilha\n");
    while(l != NULL){
        printf("Valor[%d]: %d\n", cont, l->valor);
        cont++;
        l = l->prox;
    }
    printf("\n");
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

void addLista(No **lista, int v[], int size){
    int cont = size;
    for(int i = 0; i < cont; i++)
        push(lista, v[i]);
}

int isVazio(No *l){
    if(l != NULL) return 0;
    return 1;
}

No *intercala_lista(No *p1, No *p2){ // problema em add um no impar e outro par
    No *p3 = NULL;

    if(p1 == NULL){
        p3 = p2;
        return p3;
    }

    if(p2 == NULL){
        p3 = p1;
        return p3;
    }

    while(p1 != NULL && p2 != NULL){     
        
        if(!isVazio(p1)){
            push(&p3, p1->valor);
            p1 = p1->prox;
        }
        
        if(!isVazio(p2)){
            push(&p3, p2->valor);
            p2 = p2->prox;
        }
        
    }
    return p3;
}

No *intercala_lista2(No *p1, No *p2) { // este foi do gpt
    No *p3 = NULL; 
    int alterna = 1; // Variável para alternar entre as listas

    
    while (p1 != NULL || p2 != NULL) {
        if (alterna && p1 != NULL) { // Adiciona de p1 quando alterna é 1
            push(&p3, p1->valor);
            p1 = p1->prox;
        } else if (!alterna && p2 != NULL) { // Adiciona de p2 quando alterna é 0
            push(&p3, p2->valor);
            p2 = p2->prox;
        }
        // Alterna a variável para mudar de lista na próxima iteração
        alterna = !alterna;
        
        // Se uma das listas acabar, continua com a outra
        if (p1 == NULL) alterna = 0; // Se p1 terminou, passa a usar p2
        if (p2 == NULL) alterna = 1; // Se p2 terminou, passa a usar p1
    }

    return p3;
}

int main(){
    No *lista = NULL, *lista2 = NULL, *lista3 = NULL;
    int vetor1[] = {2,3};
    int vetor2[] = {8,7,3};
    addLista(&lista, vetor1, sizeof(vetor1) / sizeof(vetor1[0]));
    addLista(&lista2, vetor2, sizeof(vetor2) / sizeof(vetor2[0]));

    lista3 = intercala_lista(lista, lista2);

    print(lista);
    printf("\n");
    print(lista2);
    printf("\n");

    printf("Todos os valores ao final da lista.\n");
    print(lista3);
    return 0;
}