#include <stdlib.h>
#include <stdio.h>

typedef struct ArvBin{
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
}TNo;

TNo *push(TNo *no, int v);
void preOrdem(TNo *no);
void emOrdem(TNo *no);
void posOrdem(TNo *no);
void printFolha(TNo *no, int v);
int altura(TNo *no);
int ContNo(TNo *no);
TNo *search(TNo *no, int v);

int main(){
    TNo *no = NULL;

    no = push(no, 50);
    no = push(no, 30);
    no = push(no, 70);
    no = push(no, 20);
    no = push(no, 40);
    no = push(no, 60);
    no = push(no, 80);

    printf("Pre ordem: ");
    preOrdem(no);
    printf("\n");

    printf("Em ordem: ");
    emOrdem(no);
    printf("\n");

    printf("Pos ordem: ");
    posOrdem(no);
    printf("\n");

    printf("Numero de nos: %d\n", ContNo(no));

    int key = 40;
    TNo *searchResult = search(no, key);
    if (searchResult) {
        printf("No %d encontrado.\n", searchResult->info);
    } else {
        printf("No %d nao encontrado.\n", key);
    }

    printf("Altura da arvore: %d\n", altura(no));

    printf("Folhas de: ");
    printFolha(no, 30);
    return 0;
}

// Inserir no na arvore
TNo *push(TNo *no, int v){
    if(no == NULL){
        TNo *novo = (TNo*) malloc(sizeof(TNo));
        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if(v > no->info)
        no->dir = push(no->dir,v);
    else
        no->esq = push(no->esq,v);
    return no;
}

//Formas de Printar a Arvore

// Pre ordem (raiz-esquerda-direita)
void preOrdem(TNo *no){
    if( no != NULL){
        printf("%d ", no->info);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

// Em ordem (esquerda-raiz-direita)
void emOrdem(TNo *no){
    if( no != NULL){
        emOrdem(no->esq);
        printf("%d ", no->info);
        emOrdem(no->dir);
    }
}

// Pos ordem (esquerda-direita-raiz)
void posOrdem(TNo *no){
    if( no != NULL){
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d ", no->info);
    }
}

// Printar folhas do no
void printFolha(TNo *no, int v){
    if(no != NULL){
        if(v == no->info){
            printf("%d -> ",no->info);
            if(no->esq != NULL)
                printf("%d ", no->esq->info);
            if(no->dir != NULL)
                printf("%d ", no->dir->info);
        } else {
            printFolha(no->esq,v);
            printFolha(no->dir,v);
        }
    }
}

// Altura da arvore 
int altura(TNo *no){
    if(no == NULL)
        return -1;
    else{
        int AltEsq = altura(no->esq);
        int AltDir = altura(no->dir);
        
        return (AltEsq > AltDir ? AltEsq : AltDir) + 1; // retorna maior das duas alturas e somamos 1
    }
}

// Contar No
int ContNo(TNo *no){
    if(no == NULL)
        return 0;
    return 1 + ContNo(no->esq) + ContNo(no->dir);
}

//buscar no na arvore
TNo *search(TNo *no, int v){
    if(no == NULL || no->info == v)
        return no;
    if(v < no->info)
        return search(no->esq,v);
    else
        return search(no->dir,v);
}