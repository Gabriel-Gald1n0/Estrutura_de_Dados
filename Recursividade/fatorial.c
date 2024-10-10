#include <stdio.h>
#include <stdlib.h>

/*
int fatorial(int n, int i){
    if(n == 1 || n == 0) return i;

    return fatorial(n-1, i * n);
}
*/

int fatorial(int n){
    if(n == 1 || n == 0) return 1;

    return n * fatorial(n-1);
}


int main(){
    int valor = fatorial(5);
    printf("%d\n",valor);
}