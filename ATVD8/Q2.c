#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int MDC(int a, int b);
int converte(char *str);

int main(){
    int N = 0;
    char S1[31], S2[31];
    while(1){
        scanf("%d",&N);
        if(N == -1) break;

        for(int i = 0; i < N; i++){
            scanf("%s",S1);
            scanf("%s",S2);

            int valor1 = converte(S1);
            int valor2 = converte(S2);
            if(MDC(valor1,valor2) > 1)
                printf("Pair #%d: All you need is love!\n", i+1);
            else 
                printf("Pair #%d: Love is not all you need!\n", i+1);
        }
    }
    return 0;
}

int MDC(int a, int b){
    if(b == 0) return a;

    return MDC(b, a%b);
}

int converte(char *str){
    int decimal = 0;
    int tam = strlen(str);

    for(int i = 0; i < tam; i++)
        if(str[i] != '0')
            decimal += pow(2,tam - i - 1);
    
    return decimal;
}