#include <stdio.h>
#include <stdlib.h>

/*
int somatorio(int n, int i){ // i comeca em 1 ou 0
    if(n == 1) return i;

    return somatorio(n-1, i + n);
}
*/

int somatorio(int n){
    if(n == 1) return 1;

    return n + somatorio(n-1);
}


int main(){
    int valor = somatorio(3);
    printf("%d\n",valor);
}