/*
Dado um vetor de números inteiros não ordenado, escreva um programa que determine se existem
dois elementos no vetor cuja soma seja exatamente igual a um número alvo x. O programa deve
retornar "Sim"se houver dois elementos com a soma igual a x , ou "Não"caso contrário.
*/
#include <stdio.h>
#include <stdlib.h>

void bobbleSort(int v[], int n); // como é um conjunto de numero pequenos acredito ser mais eficiente para ser usado
int Prog(int v[], int n, int x);

int main(){
     // Vetor ordenado e valor de x
    int v[] = {2,14,33,23,5,6,7,22,10,8};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 20;
    bobbleSort(v,n);

    int result = Prog(v,n,x);
    printf("\n\n");

    if(result == 1){
        printf("SIM\n");
    } else
        printf("Nao\n");
    printf("\n\n");

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

int Prog(int v[], int n, int x){
    int ini = 0, fim = n-1;

    while(ini <= fim){
    int soma = v[ini] + v[fim];
        if(soma == x){
            //printf("%d %d", v[ini], v[fim]);
            return 1;
        }
        else if (soma < x)
            ini++;
        else   
            fim--;
    }

    return 0;
}
