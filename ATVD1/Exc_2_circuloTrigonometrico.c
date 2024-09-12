#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcQuadrante(int R);
int verificaQuadrante(int Quadrante);

int main(void) {
  int R = 0;
  while (R != -1) {
    printf("Digite o valor de R: ");
    scanf("%d", &R);

    if (0 <= R && R <= 1000000000)
      calcQuadrante(R);
    else
      printf("Erro: Valor de R invalido.\n");
  }
  return 0;
}

int verificaQuadrante(int x) {
  if (0 <= x && x < 90)
    return 1;
  if (90 <= x && x < 180)
    return 2;
  if (180 <= x && x < 270)
    return 3;
  if (270 <= x && x < 360)
    return 4;
  return 0;
}

void calcQuadrante(int R) {
  int numVoltas = 0, quadrante = 0;
  char *str = malloc(11 * sizeof(char));
  str[0] = '\0';

  numVoltas = R / 360;
  quadrante = R % 360;

  switch (verificaQuadrante(quadrante)) {
  case 1:
    strcat(str, "primeiro");
    break;
  case 2:
    strcat(str, "Segundo");
    break;
  case 3:
    strcat(str, "Terceiro");
    break;
  case 4:
    strcat(str, "Quarto");
    break;
  default:
    break;
  }

  printf("\nQUADRANTE: %s Quadrante \n", str);
  printf("NUMERO DE VOLTAS: %d\n\n", numVoltas);
  free(str);
}