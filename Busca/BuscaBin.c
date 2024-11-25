#include <stdio.h>
#include <stdlib.h>

int buscaBin(int v[], int n, int chave);
void insertSort(int v[], int n);
void selectionSort(int v[], int n);
void bobbleSort(int v[], int n);
int particiona(int *v, int inicio, int fim);
void quickSort(int v[], int ini, int fim);

int main(){
    int n = 7;
    int v[] = {50,30,20,70,40,80,60};

    printf("Vetor Desordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    bobbleSort(v,n);
    
    printf("\n");
    printf("Vetor ordenado: ");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n");
    int buscaResult = buscaBin(v, n, 70);
    if( buscaResult > 0)
        printf("Valor encontrado: %d", buscaResult);
    else
        printf("Valor nao encontrado");

    return 0;
}

int buscaBin(int v[], int n, int chave){
    int ini = 0, fim = n-1, meio;
    while(ini <= fim){
        meio = (ini + fim)/2;

        if(v[meio] == chave)
            return v[meio];
        else if (v[meio] < chave)
            ini = meio + 1;
        else 
            fim = meio -1;
    }
    return -1;
}

// Metodos de ordenação

// Insert sort
void insertSort(int v[], int n){
    for(int i = 1; i < n; i++){
        int chave = v[i];
        int j = i - 1;
        while(j >=0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}

// Selection sort
void selectionSort(int v[], int n){
    for(int i = 0; i < n-1 ; i++){
        int menorIndice = i;

        for(int j = i + 1; j < n; j++)
            if(v[j] < v[menorIndice])
                menorIndice = j;
        
        int temp = v[menorIndice];
        v[menorIndice] = v[i];
        v[i] = temp;
    }
}

// Bobble sort
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
        quickSort(v, pos,fim);
    }
}