#include <stdio.h>
#include <stdlib.h>

void moda(int v[], int n);

int main(){
    int n = 10;
    int v[] = { 1, 3, 5, 5,5, 6, 6, 7, 7, 7, 9};
    
    moda(v,n);
    return 0;
}

void moda(int v[], int n){
    int *newV;
    newV = (int*) calloc(10,sizeof(int));
    int freq = 0;

    // conta as frequencias
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] == v[j]){
                newV[i]++;
            }
        }
        if(newV[i] > freq){
            freq = newV[i];
        }
    }

    // verifica a moda
    int cont=0;
    for(int i = 0; i < n; i++){
        if(newV[i] == freq){
            if(i == 0 || v[i] != v[i-1]){
                printf("%d ", v[i]);
                cont++;
            }
        }
    }

   
    // verifica o tipo de moda
    if (freq == 1) {
        printf("Nao modal\n");
    } else if (cont == 1) {
        printf("Unimodal\n");
    } else if (cont == 2) {
        printf("Bimodal\n");
    } else 
        printf("Multimodal\n");
    
    free(newV);
}