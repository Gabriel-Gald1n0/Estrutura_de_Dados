#include <stdlib.h>
#include <stdio.h>

struct l{
    int num;
    struct l *prox;
};

typedef struct l lista;

void insere(char c,int n, lista **p);
void imprime(lista *p);

int main(void){
    lista *l1 = NULL;
    int n = 0, num = 0;
    char c;

    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        if( 0 <= n && n <= 10000){

            for(int i = 0; i < n; i++){
                do{
                scanf(" %c %d",&c, &num);
                if(c == 'P' || c == 'U'){
                    insere(c,num,&l1);
                    break;
                }else
                    printf("DIGITE P ou U\n");
                } while (1);
            }
        
        imprime(l1);
        l1 = NULL;
        }else
            printf("O valor de N fora do intervalo\n");
    }
}

void insere(char c,int n, lista **p){
    lista *nova = (lista*) malloc(sizeof(lista));

    if(nova == NULL){
        printf("Erro de alocação de memória!\n");
        return;
    }
    
    nova->num = n;
    nova->prox = NULL;
    lista *temp = *p;

    switch (c)
    {
    case 'P':
        nova->prox = *p;
        *p = nova;
        break;
    case 'U':
        if(*p == NULL)
            *p = nova;
        else{
            while(temp->prox != NULL){
                temp = temp->prox;
            }
            temp->prox = nova;
        }
        break;

    default:
        printf("Caractere Nao encontrado\n");
        free(nova);
        break;
    }
    
}

void imprime(lista *p){
    lista* novo = p;
    while(novo != NULL){
        printf("%d ", novo->num);
        novo = novo->prox;
    }
    printf("\n");
}

