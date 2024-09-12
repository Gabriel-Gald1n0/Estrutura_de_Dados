#include "biblioteca2.h"

int main(void) {
  int entrada = -1, cont = 0;
  contato *agenda = NULL;
  agenda = (contato*) malloc(MAX * sizeof(contato));
  if (agenda == NULL){
    printf("Erro de Alocacao");
    exit(1);
  }

  do {
    printf("\nMenu:\n");
    printf("1. Adicionar Contato\n");
    printf("2. Visualizar Contatos\n");
    printf("3. Buscar Contato\n");
    printf("4. Remover Contato\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &entrada);
    switch (entrada) {
    case 1:
      addContatos(&agenda,&cont);
      break;
    case 2:
      printContatos(agenda,cont);
      break;
    case 3:
      searchContatos(agenda,cont);
      break;
    case 4:
      deleteContato(agenda,&cont);
      break;
    case 0:
      entrada = 0;
      break;
    }
  } while (entrada != 0);
  
  free(agenda);
  return 0;
}
