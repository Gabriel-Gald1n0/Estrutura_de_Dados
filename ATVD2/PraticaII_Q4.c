#include <stdio.h>
#include <stdlib.h>

int *alocaArray(int n);
void buscarArray(int *array, int *arrayBusca, int b, int n);

int main(void) {
  int *p, n = -1, b = -1, *x;

  while (n != 0) {
    
    scanf("%d", &n);
    if (n > 0 && n < 1000) {
      p = alocaArray(n);
      
      for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
        if (p[i] < 0 || p[i] > 1000) {
          scanf(" %d", &p[i]);
        }
      }

      scanf("%d", &b);
      if (b > 0 && b < 100) {
        x = alocaArray(b);
        for (int i = 0; i < b; i++) {
          scanf(" %d", &x[i]);
          if (x[i] < 0 || x[i] > 1000) {
            printf("Digite um valor valido: ");
            scanf(" %d", &x[i]);
          }
        }
        printf("\n");
        buscarArray(p, x, b, n);
      } else
        printf("Erro: Valor da coluna inválido\n");
    } else
      printf("ERRO: Valor inválido\n");
  }
  return 0;
}

int *alocaArray(int n) {
  int *p = (int *)malloc(n * sizeof(int));

  if (p == NULL)
    return NULL;

  return p;
}

void buscarArray(int *array, int *arrayBusca, int b, int n) {
  for (int i = 0; i < b; i++) {
    int cont = 0;
    for (int j = 0; j < n; j++)
      if (array[j] == arrayBusca[i]) {
        printf("%d\n", j + 1);
        cont = 1;
        break;
      }
    if (!cont)
      printf("NAO\n");
  }
  printf("\n");
}