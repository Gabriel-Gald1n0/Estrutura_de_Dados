/*
Dado um vetor de números inteiros ordenado em ordem crescente, implemente uma função que,
utilizando o algoritmo de busca binária, identifique dois elementos consecutivos no vetor cuja
soma seja a mais próxima possível de um número inteiro x.
1. A função deve retornar os dois elementos encontrados.
2. Se houver mais de um par com a mesma proximidade, retorne o primeiro par encontrado.

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void BuscaBin(int v[], int n, int x ,int *v1, int *v2);

int main(){
 // Vetor ordenado e valor de x
    int v[] = {1, 3, 5, 8, 12, 15, 19, 22};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 20;

    // Variáveis para armazenar o resultado
    int res1, res2;

    // Chama a função
    BuscaBin(v, n, x, &res1, &res2);

    // Exibe o resultado
    printf("O par cuja soma e mais proxima de %d e: (%d, %d)\n", x, res1, res2);

    return 0;
}


void BuscaBin(int v[], int n, int x ,int *v1, int *v2){
    int ini = 0, fim = n - 1, menorDif;
    menorDif = abs(v[ini] + v[fim] - x); // abs calcula valor absoluto

    *v1 = v[ini];
    *v2 = v[fim]; 

    int soma = 0, dif = 0;

    while(ini <= fim){
        soma = v[ini] + v[fim];
        dif = abs(soma - x);

        if(dif < menorDif){
            menorDif = dif;
            *v1 = v[ini];
            *v2 = v[fim]; 
        }

        if(soma < x)
            ini++;
        else
            fim--;
    }
}