/*
Dado um vetor de números inteiros não ordenado, construa uma Árvore Binária de Busca (ABB)
a partir da sequência de inserção dos elementos no vetor. Apresente a estrutura final da árvore
após todas as inserções. Realize um percurso em ordem (in-order) na árvore e exiba o resultado.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ArvBin{
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} Tno;

Tno *push(Tno *no, int n);
void emOrdem(Tno *no);

int main(){
    Tno *no = NULL;
    int v,n;

    while(1){
        
        printf("1- Inserir\n2- Imprimir\n");
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
            printf("Arvore:\n");
            emOrdem(no);
        default:
            break;
        }
        printf("\n");
    }
    return 0;  
}

Tno *push(Tno *no, int n){
    if(no == NULL){
        Tno *novo = (Tno*) malloc(sizeof(Tno));
        novo->info = n;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if(n < no->info)
        no->esq = push(no->esq,n);
    else
        no->dir = push(no->dir,n);

    return no;
}

// em ordem (esquerda-raiz-direita)
void emOrdem(Tno *no){
    if(no != NULL){
        emOrdem(no->esq);
        printf("%d ", no->info);
        emOrdem(no->dir);
    }
}
