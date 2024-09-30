#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
    struct no *ant;
} No;

void incLista(No **l, int n)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = n;
    novo->prox = *l;
    novo->ant = NULL;

    if(*l != NULL)
        (*l)->ant = novo;
    *l = novo;
}

void incFimLista(No **l, int n)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->valor = n;
    novo->prox = NULL;
    
    if (*l == NULL){
        novo->ant = NULL;
        *l = novo;
    } else {
        No *aux = *l;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
}

void print(No *l)
{
    while (l->prox != NULL){
        l = l->prox;
    }
    
    printf("Lista Decrescente:\n");
    while (l != NULL)
    {
        printf("valores: %d\n", l->valor);
        l = l->ant;
    }
    printf("\n");
}

void printFor(No *l)
{
    int cont = 0;
    No *novo = l;
    printf("Lista:\n");
    for (novo = l; novo != NULL; novo = novo->prox)
    {
        printf("Valores[%d]: %d\n", cont, novo->valor);
        cont++;
    }
    printf("\n");
}

void pop(No **l, int num){
    No *novo = NULL;
    No *aux = *l;

    if(aux == NULL){
        return;
    }

    if(aux->valor == num){
        *l = aux->prox;
        if(*l != NULL)
            (*l)->ant = NULL;
        free(aux);
    }else{
        while(aux->prox != NULL && aux->prox->valor != num) {
            aux = aux->prox;
        }
        if(aux->prox != NULL){
            novo = aux->prox;
            aux->prox = novo->prox;
            novo->ant = aux;
            if(aux->prox != NULL)
                aux->prox->ant = aux;
            free(novo);
        }else{
            printf("Nao tem o numero %d neste no\n",num);
        }
            
    }
}

void removeNode(No **l, int n){
    No *aux = *l;
    No *novo = NULL;

    if(*l == NULL){
        printf("Lista Vazia\n");
        return;
    }

    if(aux->valor == n){
        *l = aux->prox;
        if(*l != NULL)
            (*l)->ant = NULL;
        free(aux);
    }else{
        while(aux->prox != NULL && aux->prox->valor != n)
            aux = aux->prox;
        if(aux->prox != NULL){
            novo = aux->prox;
            aux->prox = novo->prox;
            novo->ant = aux;
            if(aux->prox != NULL)
                aux->prox->ant = aux;
            free(novo);
        }else{
            printf("O num nao esta na lista\n");
        }
    }
}

void search(No *l, int n){
    No *aux = l;
    int cont = 0;

    if(aux == NULL){
        printf("Lista Vazia\n");
        return;
    }

    while(aux != NULL){
        if(aux->valor == n){
            printf("O valor %d esta [%d]\n",aux->valor,cont);
            return;
        }
        cont++;
        aux = aux->prox;
    }
    printf("Valor nao encontrado\n");   
}

No *concatena(No *l1, No *l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    No *aux = l1;
    while (aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = l2;
    l2->ant = aux;
    
    return l1;
}

void addLista2(No **lista2){
    int V[3] = {1,2,3};
    for(int i = 0; i < 3; i++)
        incLista(lista2, V[i]);
}

void listaImparPar(No **l,No **p, No **i){
    No *aux = *l;

    while(aux != NULL){   
        if(aux->valor >= 0){
            if(aux->valor % 2 == 0){
                incLista(p,aux->valor);
            }else {
                incLista(i,aux->valor);
            }
        }
        aux = aux->prox;
    }
}

int main()
{
    No *lista = NULL;
    No *lista2 = NULL;
    No *lista3 = NULL;
    No *par = NULL, *impar = NULL;
    int v = 0, op = 0;

    int V[3] = {1,2,3};
    for(int i = 0; i < 3; i++)
        incLista(&lista2, V[i]);

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
            incLista(&lista, v);
            break;
        case 2:
            scanf("%d", &v);
            incFimLista(&lista, v);
            break;
        case 3:
            scanf("%d", &v);
            removeNode(&lista,v);
            break;
        case 4:
            scanf("%d", &v);
            search(lista,v);
            break;
        case 5:
            lista3 = concatena(lista,lista2);
            print(lista3);
            lista2 = NULL;
            addLista2(&lista2);
            break;
        case 6:
            listaImparPar(&lista, &par, &impar);
            print(par);
            print(impar);
            break;
        case 7:
            print(lista);
            break;
        case 8:
            printFor(lista);
            break;
        default:
            break;
        }
    }
    printf("Todos os valores ao final da lista.\n");
    printFor(lista);
    return 0;
}
