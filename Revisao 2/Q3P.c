#include <stdio.h>
#include <stdlib.h>

void moda(int v[], int n);

int main(){
    int n = 7;
    int v[] = { 3,3,3,4,4,5,7};
    
    moda(v,n);
    return 0;
}

void moda(int v[], int n){
    int *newV;
    newV = (int*) calloc(n,sizeof(int));
    int res = n/3;

    // conta as frequencias
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] == v[j]){
                newV[i]++;
            }
        }
    }

    if(res == 1 || n == 2){
        printf("Nao possui valor\n");
        return;
    }

    for(int i = 0; i < n; i++){
        if(newV[i] >= res){
            if(i == 0 || v[i] != v[i-1]){
                printf("%d ", v[i]);
            }
        }
    }

   
    
    free(newV);
}