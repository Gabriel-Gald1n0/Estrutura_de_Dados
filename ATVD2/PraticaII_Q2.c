#include <stdio.h>
#include <stdlib.h>
int *alocaArray(int n);
int *somaArray(int *p, int *c, int n);

int main(void) {
  int *p, *c, n = 0, *s;

  while (n != -1) {
    printf("Digite o tamanho do Array: ");
    scanf("%d", &n);
    if (n > 0 && n < 1000) {
      p = alocaArray(n);
      c = alocaArray(n);
      printf("Digite os valores do 1° Array:\n");
      for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
        if (p[i] < 0 || p[i] > 1000) {
          printf("Valor inválido, digite novamente: ");
          scanf(" %d", &p[i]);
        }
      }

      printf("\nDigite os valores do 2° Array:\n");
      for (int i = 0; i < n; i++) {
        scanf(" %d", &c[i]);
        if (c[i] < 0 || c[i] > 1000) {
          printf("Valor inválido, digite novamente: ");
          scanf(" %d", &c[i]);
        }
      }
      s = alocaArray(n);
      s = somaArray(p, c, n);
      printf("\nA soma dos valores do Array é:\n");
      for (int i = 0; i < n; i++)
        printf("%d\n", s[i]);
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

int *somaArray(int *p, int *c, int n) {
  int *soma = alocaArray(n);
  for (int i = 0; i < n; i++) {

    soma[i] = p[i] + c[n - i - 1];
  }

  return soma;
}