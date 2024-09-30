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
    if(*l == NULL){
        novo->prox = NULL;
        *l = novo;
    }else{
        No *aux = *l;
        while(aux->prox != NULL)
            aux = aux->prox;
        novo->prox = NULL;
        aux->prox = novo;
    }
}

void pop(No **l){
    No *novo = (No*)malloc(sizeof(No)); // NULL tbm funciona

    if(*l == NULL){
        printf("Fila vazia\n");
        return;
    }

    novo = *l;
    *l = (*l)->prox;
    free(novo);
}

void print(No *l){
    int cont = 0;
    if( l == NULL){
        printf("Fila vazia\n");
        return;
    }
         
    printf("Fila\n");
    while(l != NULL){
        printf("Valor[%d]: %d\n", cont, l->valor);
        cont++;
        l = l->prox;
    }
    printf("\n");
}

void frente(No *l){
    if( l == NULL){
        printf("Fila vazia\n");
        return;   
    }
         
    printf("frente: %d\n", l->valor);
}

No *concatena(No *l1, No *l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    No *aux = l1;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = l2;

    return l1;
}

void addLista2(No **lista2){
    int V[3] = {1,2,3};
    for(int i = 0; i < 3; i++)
        push(lista2, V[i]);
}

int contador(No *l){
    int cont = 0;
    while(l != NULL){
        cont++;
        l = l->prox;
    }
    return cont;
}

No *list(No *l, int n){
    No *novo = NULL;
    if(l == NULL)
        return novo;
    No *aux = l;
    int cont = 1;
    while(aux->prox != NULL && n != cont){
        cont++;
        aux = aux->prox;
    }

    if(aux != NULL){
        novo = aux->prox;
    }else
        return novo;
    return novo;
}

No *inverte(No *l){
    No *atual = l;
    No *prox = NULL;
    No *ant = NULL;

    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox; 
    }
    return ant;
}

int main(){
    No *lista = NULL, *lista2 = NULL;
    int v = 0, op = 0;
    addLista2(&lista2);

    int cont; 
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
            break;
        case 5:
            frente(lista);
            break;
        case 6:
            cont = contador(lista);
            if(cont) printf("Cont No: %d\n",cont);
            else printf("NULL\n");
            break;
        case 7:
            scanf("%d", &v);
            lista = list(lista,v);
            break;
        case 8:
            lista = inverte(lista);
            break;
        default:
            break;
        }
    }
    printf("Todos os valores ao final da Fila.\n");
    print(lista);
    return 0;
}