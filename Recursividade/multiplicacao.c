#include <stdio.h>
#include <stdlib.h>

/*
int mult(int n, int m){
    if(m == 1 || n == 1) return n;
    if(n == 0 || m == 0) return 0;

    return mult(n+n, m - 1);
}
*/

int mult(int n, int m){
    if(m == 1 || n == 1) return n;
    if(n == 0 || m == 0) return 0;

    return n + mult(n, m - 1);
}

int tratamento(int n, int m){
    if((n < 0 && m >= 0) || (n >= 0 && m < 0)){
        if(n < 0) n *= -1;
        if(m < 0) m *= -1;
        return mult(n,m) * -1;
    }
    if(n < 0 && m < 0){
        if(n < 0) n *= -1;
        if(m < 0) m *= -1;
        return mult(n,m);
    }
}

int main(){

    int valor = tratamento(-5,-3);
    printf("%d\n",valor);
}