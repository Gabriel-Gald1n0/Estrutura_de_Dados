#include <stdio.h>

void troca(int *a, int *b);

int main(void) {
  int a = 0,b;
  while(a != -1)
    {
      printf("Digite o valor de a e b: ");
      scanf("%d %d", &a, &b);

      if(a < 1000000 && b < 1000000)
      {
        printf("%d %d\n", a, b);
        troca(&a, &b);
        printf("%d %d\n", a, b);
      }
      else
        printf("Digite um valor menor que 1000000\n");
      
    }
  return 0;
}

void troca(int *a, int *b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}