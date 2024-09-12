#include "biblioteca1.h"

void addIntervalo(intervalo **intervalos, int *tamanho) {
  int inicio, fim;
  *intervalos =
      (intervalo *)realloc(*intervalos, (*tamanho + 1) * sizeof(intervalo));

  if (*intervalos == NULL){
    printf("ERRO DE ALOCACAO");
    exit(1);
  }
    
  scanf("%d %d", &inicio, &fim);

  if (inicio > fim)
  {
    printf("Intervalo de inicio maior que o intervalo final");
    exit(1);
  }
    
  (*intervalos)[*tamanho].inicio = inicio;
  (*intervalos)[*tamanho].fim = fim;
  (*tamanho)++;
}

void verificarIntervalo(intervalo *intervalos, int tamanho) {
  int ponto;
  int find = 0;
  scanf("%d", &ponto);
  for (int i = 0; i < tamanho; i++) {
    if (ponto >= intervalos[i].inicio && ponto <= intervalos[i].fim) {
      printf("Dentro do intervalo [%d, %d]\n", intervalos[i].inicio,
             intervalos[i].fim);
      find = 1;
    }
  }
  if (!find)
    printf("Fora de todos os intervalos\n");
}
