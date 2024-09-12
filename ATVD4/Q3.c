#include <stdlib.h>
#include <stdio.h>

struct l{
    int num;
    struct l *prox;
};

typedef struct l lista;

void insere(int n, lista **p);
void imprime(lista *p);
lista* reordena_lista(lista* l);

int main(void){
    lista *l1 = NULL;
    int n = 0, num = 0;

    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        if( 0 <= n && n <= 100){
            for(int i = 0; i < n; i++){
                scanf("%d", &num);
                insere(num,&l1);
            }
        imprime(l1);

        lista *l1_reodernar = reordena_lista(l1);
        if(l1_reodernar)
            imprime(l1_reodernar);
        else
            printf("Lista Vazia\n");
        l1_reodernar = NULL;
        l1 = NULL;
        }else
            printf("O valor de N fora do intervalo\n");
    }
}

void insere(int n, lista **p){
    lista *nova = (lista*) malloc(sizeof(lista));

    if(nova != NULL){
        nova->num = n;
        nova->prox = NULL;
    }
    
    //nova->num = n;
    //nova->prox = *p;
    //*p = nova;
    
    lista *temp = *p;
    if(*p == NULL)
        *p = nova;
    else{
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = nova;
    }
}

void imprime(lista *p){
    lista* novo = p;
    while(novo != NULL){
        printf("%d->", novo->num);
        novo = novo->prox;
    }
    printf("NULL\n");
}

lista* reordena_lista(lista* l){
    lista *i, *j, *aux;

    if (l == NULL || l->prox == NULL)
        return l;
    
    for(i = l; i != NULL; i = i->prox){
        aux = i;
        for(j = i->prox; j != NULL; j = j->prox){
            if(j->num % 2 == 1){
                aux = j;
            }   
        }
        if(aux != i){
            int temp = i->num; //i->num e guardado em temp
            i->num = aux->num;// i->num recebe o valor de aux->num
            aux->num = temp;// aux->num recebe o valor de temp que tinha i->num e assim ocorre a troca
        }
    }

    return l;
}

