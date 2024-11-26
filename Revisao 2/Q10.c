/*
Considerando uma estrutura de árvore binária que armazena valores inteiros definida pelo tipo
abaixo:

Código em C

struct arv {
int info;
struct arv* esq;
struct arv* dir;
};
typedef struct arv Arv;

Escreva uma função que retorne a soma dos números inteiros armazenados em nós que são folhas
da árvore (isto é, nós que não têm filhos). O protótipo da função deve ser:

int soma_info_folhas (Arv* a);
*/
#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;
Arv *push(Arv *no, int v);
int soma_info_folhas(Arv *a);

int main(){
    Arv *no = NULL;
    int v,n;

    while(1){
        
        printf("1- Inserir\n2- Soma\n");
        scanf("%d",&v);
        if(v == -1) break;

        switch (v)
        {
        case 1:
            printf("Insira o valor: ");
            scanf("%d",&n);
            no = push(no,n);
            break;
        case 2:
            printf("Soma: %d\n", soma_info_folhas(no));
        default:
            break;
        }
        printf("\n");
    }
    return 0;
}

Arv *push(Arv *no, int v){
    if(no == NULL){
        Arv *novo = (Arv*) malloc(sizeof(Arv));
        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(v < no->info)
        no->esq = push(no->esq, v);
    else 
        no->dir = push(no->dir, v);
    
    return no;
}

int soma_info_folhas(Arv *a){
    if(a == NULL)
        return 0; 

    if(a->dir == NULL && a->esq == NULL)
        return a->info; 
    
    return soma_info_folhas(a->esq) + soma_info_folhas(a->dir);
}
