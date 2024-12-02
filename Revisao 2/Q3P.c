#include <stdio.h>
#include <stdlib.h>

void prog(int v[], int n);
void bobbleSort(int v[], int n);

int main(){
    int n = 7;
    int v[] = { 4,5,3,4,3,3,7};
    
    bobbleSort(v,n);
    prog(v,n);
    return 0;
}

void prog(int v[], int n){
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
            if(i == 0 || v[i] != v[i-1]){ //// errei apenas o sinal dentro do v[i - 1] e acabei me confundindo e colocando v[i+1]
                printf("%d ", v[i]);
            }
        }
    }
    free(newV);
}

void bobbleSort(int v[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}