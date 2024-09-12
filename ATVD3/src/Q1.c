#include "biblioteca1.h"

int main(void) {
  int entrada, tamanho = 0;
  intervalo *intervalos = NULL;
  
  do {
    scanf("%d", &entrada);
    switch (entrada) {
    case 1:
      addIntervalo(&intervalos, &tamanho);
      break;
    case 2:
      verificarIntervalo(intervalos, tamanho);
      break;
    case 0:
      entrada = 0;
      break;
    }
  } while (entrada != 0);
  free(intervalos);
  return 0;
}
