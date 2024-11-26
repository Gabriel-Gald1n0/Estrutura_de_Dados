/*
Dado um vetor de números inteiros com n elementos, implemente um programa que encontre os
k menores elementos do vetor e os retorne em ordem crescente.
1. O programa deve funcionar corretamente independentemente da ordem inicial dos elementos
no vetor.
2. Utilize um algoritmo de ordenação eficiente e justifique a escolha no seu código.
*/
#include <stdio.h>
#include <stdlib.h>

void bobbleSort(int v[], int n); // como é um conjunto de numero pequenos acredito ser mais eficiente para ser usado
void Prog(int v[], int n, int k);

int main(){
     // Vetor ordenado e valor de x
    int v[] = {2,14,33,23,5,6,7,22,10,8};
    int n = sizeof(v) / sizeof(v[0]);
    int k = 20;

    Prog(v,n,k);

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


void Prog(int v[], int n, int k){
    int *v2 = (int*) malloc(n * sizeof(int));
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(v[i] < k){
            v2[cont] = v[i];
            cont++;
        }
    }

    bobbleSort(v2,cont);

    printf("Numeros menores que %d:\n",k);
    for(int i = 0; i < cont; i++){
        printf("%d ", v2[i]);
    }

    free(v2);
}

