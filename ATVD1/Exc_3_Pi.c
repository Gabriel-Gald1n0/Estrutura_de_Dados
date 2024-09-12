#include <stdio.h>

double aprox_pi(int n);

int main(void) {
  int numTermos = 1;

  while (numTermos > 0) {
    printf("Digite o numero de Termos: ");
    scanf("%d", &numTermos);

    if (numTermos >= 1)
      printf("Aproximacao de PI: %.5f\n", aprox_pi(numTermos));
    else
      printf("Numero de termos invalido. Deve ser maior ou igual a 1.");
  }
  return 0;
}

double aprox_pi(int n) {
  double pi = 0.0;
  for (int i = 0; i < n; i++)
    pi += 4.0 * ((i % 2 == 0.0 ? 1.0 : -1.0) / (2.0 * i + 1.0));
  return pi;
}