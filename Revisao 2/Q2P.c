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

int BuscaBin(int v[], int n, int x);

int main(){
 // Vetor ordenado e valor de x
    int v[] = {2, 3, 5, 8, 12, 15, 19, 22};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 20;

    // Chama a função
    int res = BuscaBin(v, n, x);

    // Exibe o resultado
    printf("O par cuja soma e mais proxima de %d e: %d\n", x, res);

    return 0;
}


int BuscaBin(int v[], int n, int x){
    int ini = 0, fim = n - 1, menorDif;
    menorDif = abs(v[ini] + v[fim] - x); // abs calcula valor absoluto

    int soma = 0, dif = 0;

    while(ini <= fim){
        soma = v[ini] + v[fim];
        dif = abs(soma - x);

        if(dif < menorDif){
            menorDif = dif;
            if(v[ini] < v[fim])
                return v[ini];
            else
                return v[fim];
        } else if(soma < x)
            ini++;
        else
            fim--;
    }

    return -1;
}
