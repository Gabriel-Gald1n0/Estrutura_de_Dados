#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim);
void quickSort(int v[], int ini, int fim);

int main(){
    int n = 10;
    int v[] = {2, 5, 32, 21, 102, 1, 11, 24, 35, 44, 56};

    printf("Vetor Desordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    quickSort(v, 0, n - 1);
    
    printf("\n");
    printf("Vetor ordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}


// Quick sort + particiona
int particiona(int *v, int inicio, int fim){
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
    
    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo)
            inicio = inicio + 1;
        while(inicio < fim && v[fim] > pivo)
            fim = fim - 1;
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux; 
    }
    return inicio;  
}

void quickSort(int v[], int ini, int fim){
    if(ini < fim){
        int pos = particiona(v,ini,fim);
        quickSort(v, ini, pos - 1);
        quickSort(v, pos + 1,fim);
    }
}