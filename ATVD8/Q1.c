#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *c);

int main(){
    int cont = 0;
    int N = 0, X = 0;
    while(1){
        scanf("%d",&N);
        if(N == -1) break;
        for(int i=0; i < N; i++){
            scanf("%d", &X);
            if( 1 <= X && X <= 39){
                int result = fib(X, &cont);
                printf("fib(%d) = %d Calls = %d\n", X, cont-1, result);
                cont = 0;
            } else
                printf("Invalido\n");
        }
    }
}

int fib(int n, int *c){
    (*c)+=1;
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n - 1, c) + fib(n - 2, c);
}
