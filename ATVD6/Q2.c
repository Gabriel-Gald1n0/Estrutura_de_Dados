#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char valor;
    struct no *prox;
} No;

void push(No **l, char n);
char pop(No **l);
int verifica(char *str);

int main(){
    char sequencia[1001];
    
    while (fgets(sequencia, 1001, stdin)) {
        if (sequencia[0] == '\n') {
            break; // Encerra ao receber uma linha vazia
        }

        if (verifica(sequencia)) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }

    return 0;
}

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

int verifica(char *str){
    No *p = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        char atual = str[i];

        // Se for um caractere de abertura, empilha
        if (atual == '(' || atual == '[' || atual == '{') {
            push(&p, atual);
        }
        // Se for um caractere de fechamento, verifica a correspondência
        else if (atual == ')' || atual == ']' || atual == '}') {
            char topo = pop(&p);
            if ((atual == ')' && topo != '(') ||
                (atual == ']' && topo != '[') ||
                (atual == '}' && topo != '{')) {
                return 0;  // Se não corresponde, retorna não bem-formado
            }
        }
        // Verifica se há caracteres inválidos (qualquer coisa que não seja ( ) { } [ ])
        else if (((atual >= 'a' && atual <= 'z') || (atual >= 'A' && atual <= 'Z') || (atual >= '0' && atual <= '9'))) {
            return 0;  
        }
    }

    // Se a pilha não estiver vazia, significa que há algum par que não foi fechado corretamente
    return p == NULL; 
}