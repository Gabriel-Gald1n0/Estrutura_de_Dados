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

void pushF(No **l, int n){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = NULL;
    if(*l == NULL){
        *l = novo;
    }else{
        No *aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
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

void topo(No *l){
    if( l == NULL){
        printf("Pilha vazia\n");
        return;   
    }
         
    printf("Topo: %d\n", l->valor);
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

No *copy(No *l){
    No *aux = l;
    No *copy = NULL;

    while(aux != NULL){
        pushF(&copy, aux->valor);
        aux = aux->prox;
    }
    return copy;
}

void addLista2(No **lista2){
    int V[3] = {1,2,3};
    for(int i = 0; i < 3; i++)
        push(lista2, V[i]);
}

int verifica(No *p1, No *p2){
    while(p1 != NULL && p2 != NULL){
        if(p1->valor == p2->valor){
            p1= p1->prox;
            p2= p2->prox;
        }
        else return 0;
    }

    if (p1 == NULL && p2 == NULL)
        return 1;
    else
        return 0;
}

int main(){
    No *lista = NULL, *lista2 = NULL, *lista3 = NULL;
    int v = 0, op = 0;
    addLista2(&lista2);

    while (1)
    {
        printf("Digite uma Opcao: ");
        scanf("%d", &op);
        if (op == -1)
            break;

        switch (op)
        {
        case 1:
            scanf("%d", &v);
            push(&lista, v);
            break;
        case 2:
            pop(&lista);
            break;
        case 3:
            lista = concatena(lista,lista2);
            print(lista);
            lista2 = NULL;
            addLista2(&lista2);
            break;
        case 4:
            print(lista);
            print(lista2);
            break;
        case 5:
            topo(lista);
            break;
        case 6:
            lista3 = copy(lista);
            print(lista3);
            break;
        case 7:
            if(verifica(lista,lista2)){
                print(lista2);
                print(lista);
            } else printf("sao diferentes\n");
            break;
        default:
            break;
        }
    }
    printf("Todos os valores ao final da lista.\n");
    print(lista2);
    return 0;
}