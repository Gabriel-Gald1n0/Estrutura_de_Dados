#include "biblioteca1.h"

void consultar(Expressao **ex, char *palavra, int maxCap, int *size) {
    Expressao *atual = *ex;
    Expressao *novo = NULL;

    // Verifica se a expressao existe na lista
    while (atual != NULL) {
        if (strcmp(atual->descricao, palavra) == 0) {
            // se foi encontrada, agora deve trocar com o no anterior
            if (atual->ant != NULL) {
                Expressao *anterior = atual->ant;

                // Ajusta os ponteiros para realizar a troca
                if (anterior->ant != NULL) {
                    anterior->ant->prox = atual;
                } else {
                    *ex = atual;  // Atual se torna o novo primeiro no
                }

                atual->ant = anterior->ant;
                anterior->prox = atual->prox;

                if (atual->prox != NULL) {
                    atual->prox->ant = anterior;
                }

                anterior->ant = atual;
                atual->prox = anterior;
            }
            return;  // encerra quando realiza a troca
        }
        atual = atual->prox;
    }

    // Se não foi encontrada, cria uma nova expressão
    novo = (Expressao *) malloc(sizeof(Expressao));
    strcpy(novo->descricao, palavra);
    novo->prox = NULL;
    novo->ant = NULL;

    // Verifica se a lista está cheia
    if (*size >= maxCap) {
        // Remove o último nó antes de adicionar o novo
        Expressao *ultimo = *ex;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }

        if (ultimo->ant != NULL) {
            ultimo->ant->prox = NULL;
        } else {
            *ex = NULL;  // Se houver apenas um elemento
        }

        free(ultimo);

        // Decrementa o tamanho da lista após a remoção
        (*size)--;
    }

    // Insere o novo nó no final da lista
    if (*ex == NULL) {
        *ex = novo;  // A lista estava vazia
    } else {
        atual = *ex;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }

    // Incrementa o tamanho da lista
    (*size)++;
}

void imprimeCrescente(Expressao *ini){
    Expressao *aux = ini;
    printf("\n");
    if(aux == NULL){
        printf("Lista vazia\n");
        return;
    }

    while(aux != NULL){
        printf("[%s]\n", aux->descricao);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimeDecrescente(Expressao *ini){
    Expressao *aux = ini;
    if(aux == NULL){
        printf("Lista vazia\n");
        return;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    printf("\n");

    while(aux != NULL){
        printf("[%s]\n", aux->descricao);
        aux = aux->ant;
    }
    printf("\n");
}

void historico(Expressao *lista, int n) {
    Expressao *aux = lista;
    int cont=0;

    if(aux == NULL){
        printf("Lista vazia\n");
        return;
    }

    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }

    if(n > cont) n = cont; 

    aux = lista;
    printf("Historico das ultimas %d consultas:\n\n", n);
    while (aux != NULL && n > 0) {
        printf("[%s]\n", aux->descricao);
        aux = aux->prox;
        n--;
    }

    printf("\n");
}

int cont(Expressao *ini, char *palavra){
    Expressao *aux = ini;
    int cont = 1;
    while(aux != NULL){
        if(strcmp(aux->descricao, palavra) == 0){
            return cont;
        }
        aux = aux->prox;
        cont++;
    }
    return cont;
}

void libera(Expressao **ini){
    Expressao *aux = *ini;
    while(aux != NULL){
        Expressao *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *ini = NULL;
}