#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int v[], int n, int chave);

int main(){
    int n = 7;
    int v[] = {50,30,20,70,40,80,60};

    int buscaResult = buscaLinear(v, n, 100);
    if( buscaResult > 0)
        printf("Valor encontrado: %d", buscaResult);
    else
        printf("Valor nao encontrado");

    return 0;
}

int buscaLinear(int v[], int n, int chave){
    for(int i = 0; i < n; i++){
        if(v[i] == chave)
            return v[i];
    }

    return -1;
}