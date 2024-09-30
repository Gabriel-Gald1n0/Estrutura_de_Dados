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

int pop(No **l){
    No *novo = (No*)malloc(sizeof(No));

    if(*l == NULL) return -1;

    novo = *l;
    *l = (*l)->prox;
    int n = novo->valor;
    free(novo);
    return n;
}


void converte(int num, int base){
    No *pilha = NULL;
    int d = 0;
    while(num > 0){
        d = num%base;
        push(&pilha,d);
        num = num / base;
    }

    printf("\nConversao\n");
    while(pilha != NULL){
        int n = pop(&pilha);
        if(base == 16 && n >= 10)
            printf("%c", n - 10 + 'A');
        else
            printf("%d", n);
    }
    free(pilha);
    printf("\n\n");
}

int main(){
    int num = 0, op = -1;

    do{
        printf("Decimal Para\n1- Binario\n2- Octal\n3- Hexadecimal\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            scanf("%d",&num);
            converte(num,2);
            break;
        case 2:
            scanf("%d",&num);
            converte(num,8);
            break;
        case 3:
            scanf("%d",&num);
            converte(num,16);
            break;
        default:
            op = 0;
            break;
        }
    } while(op != 0);
}