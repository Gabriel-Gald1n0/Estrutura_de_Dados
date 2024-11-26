/*
Dado um vetor de números inteiros ordenado em ordem crescente, escreva um programa para
identificar todos os elementos dentro de um intervalo [a, b].
1. O programa deve retornar os elementos encontrados em ordem crescente.
2. Caso nenhum elemento esteja dentro do intervalo, retorne "Sem elementos no intervalo".
*/
#include <stdio.h>
#include <stdlib.h>

void bobbleSort(int v[], int n); // como é um conjunto de numero pequenos acredito ser mais eficiente para ser usado
void Prog(int v[], int n, int a, int b);

int main(){
     // Vetor ordenado e valor de x
    int v[] = {2,14,33,23,5,6,7,22,10,8};
    int n = sizeof(v) / sizeof(v[0]);
    bobbleSort(v,n);

    int a = 4;
    int b = 20;

    Prog(v,n,a,b);

    return 0;
}

void bobbleSort(int v[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}


void Prog(int v[], int n, int a, int b){
    int *v2 = (int*) malloc(n * sizeof(int));
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(v[i] >= a && v[i] <= b){
            v2[cont] = v[i];
            cont++;
        }
    }

    if(cont == 0){
        printf("Sem elementos no intervalo");
        return;
    }

    bobbleSort(v2,cont);

    printf("Numeros Dentro do intervalo [%d,%d]:\n",a,b);
    for(int i = 0; i < cont; i++){
        printf("%d ", v2[i]);
    }

    free(v2);
}