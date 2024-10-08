#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int valor;
    struct pilha *prox;
} Pilha;

void empilhar(Pilha **p, int valor);
void desempilhar(Pilha **p);
void imprimir(Pilha *p);

int main() {
    int N = 0, V = 0;
    char c;
    Pilha *p = NULL; 

    while (1) {
        scanf("%d", &N);
        if (N == -1) break; // Condição de parada
        if (0 < N && N < 1000) {
            for (int i = 0; i < N; i++) {
                scanf(" %c", &c); 
                if (c == 'E') {
                    scanf("%d", &V); 
                    if (0 <= V && V <= 10000) {
                        empilhar(&p, V);
                    } else {
                        printf("Valor fora do intervalo permitido.\n");
                    }
                } else if (c == 'D') {
                    desempilhar(&p);
                } else {
                    printf("Digite um caractere que seja E / D\n");
                }

                imprimir(p);
            }
            p = NULL; 
            printf("\n"); 
        } else {
            printf("Insira um valor entre 0 e 1000\n");
        }
    }

    return 0;
}

void empilhar(Pilha **p, int valor) {
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = *p;
    *p = novo;
}


void desempilhar(Pilha **p) {
    if (*p == NULL) {
        printf("*\n"); 
        return; 
    }
    Pilha *temp = *p;
    *p = (*p)->prox; 
    free(temp); 
}

void imprimir(Pilha *p) {
    if (p == NULL) {
        printf("*\n"); 
        return;
    }

    Pilha *aux = p;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}


