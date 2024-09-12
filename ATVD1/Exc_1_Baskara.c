#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float calcular_delta(float a, float b, float c);
int verifica_raizes(float a, float b, float c);
void calcular_raizes(float a, float b, float c, float *x);

int main(void) {
  float *x = malloc(2 * sizeof(float));
  float A, B, C;

  while (A != -1) {
    printf("Digite os valores de A, B e C:\n");
    scanf("%f %f %f", &A, &B, &C);

    if (verifica_raizes(A, B, C) == 1) 
      printf("Impossivel calcular\n");
    else {
      calcular_raizes(A, B, C, x);
      printf("Raiz 1: %.5f\nRaiz 2: %.5f\n\n", x[0], x[1]);
    }
  }
  // digite -1 para A para encerar o programa
  free(x);
  return 0;
}

float calcular_delta(float a, float b, float c) {
  float delta = b * b - 4 * a * c;
  return delta;
}

void calcular_raizes(float a, float b, float c, float *x) {
    float delta = calcular_delta(a, b, c);
    x[0] = (-b + sqrt(delta)) / (2 * a);
    x[1] = (-b - sqrt(delta)) / (2 * a);
}

int verifica_raizes(float a, float b, float c) {
  if (0.1 > a || a > 100.0)
    return 1;
  if (a == 0)
    return 1;
  if (-1000.0 > b || b > 1000.0 || -1000.0 > c || c > 1000.0)
    return 1;
  if (calcular_delta(a, b, c) < 0)
    return 1;

  return 0;
}