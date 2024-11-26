/*
Dado um vetor de números inteiros, implemente um programa que ordene o vetor seguindo a
seguinte regra:
1. Números pares devem aparecer antes dos números ímpares.

2. Dentro de cada grupo (pares e ímpares), os números devem ser ordenados em ordem cres-
cente.
*/
#include <stdio.h>
#include <stdlib.h>

void bobbleSort(int v[], int n); // como é um conjunto de numero pequenos acredito ser mais eficiente para ser usado
void Prog(int v[], int n);

int main(){
     // Vetor ordenado e valor de x
    int v[] = {2,14,33,23,5,6,7,22,10,8};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Desordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ",v[i]);

    Prog(v,n);
    printf("\n\n");

    printf("Ordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ",v[i]);
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


void Prog(int v[], int n){
    int *vi = (int*) malloc(n * sizeof(int));
    int cont = 0;

    int *vp = (int*) malloc(n * sizeof(int));
    int cont2 = 0;

    for(int i = 0; i < n; i++){
        if(v[i] % 2 != 0){
            vi[cont] = v[i];
            cont++;
        } else {
            vp[cont2] = v[i];
            cont2++;
        }
    }

    bobbleSort(vi,cont);
    bobbleSort(vp, cont2);

    int cont3 = 0;
    for(int i = 0; i < cont2; i++){
        v[cont3] = vp[i];
        cont3++; 
    }

    for(int i = 0; i < cont; i++){
        v[cont3] = vi[i];
        cont3++; 
    }

    free(vi);
    free(vp);
}
