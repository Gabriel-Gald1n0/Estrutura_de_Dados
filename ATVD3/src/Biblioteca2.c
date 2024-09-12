#include "biblioteca2.h"

void addContatos(contato **agenda,  int *cont){
    char TesteNome[LIMITE_NOME+1];
    char TesteTelefone[LIMITE_TELEFONE+1];

    if(*cont >= MAX)
    {
        printf("Numero de contatos execido!\n");
        return;
    }

    printf("\nAdicionar Contatos:\n");
    printf("Nome: ");
    scanf(" %[^\n]", TesteNome);

    if(strlen(TesteNome) > LIMITE_NOME){
      printf("Erro: O nome excede o limite de %d caracteres!\n", LIMITE_NOME);
      return;
    }

    for(int i = 0; i < *cont; i++)
    {
      if(strcmp((*agenda)[i].nome,TesteNome)== 0)
      {
        printf("Erro: O nome %s ja existe na agenda\n", TesteNome);
        return;
      }
    }

    printf("telefone: ");
    scanf(" %[^\n]", TesteTelefone);
    
    if(strlen(TesteTelefone) > LIMITE_TELEFONE){
      printf("Erro: O telefone excede o limite de %d caracteres!\n", LIMITE_TELEFONE);
      return;
    }

    strcpy((*agenda)[*cont].nome,TesteNome);
    strcpy((*agenda)[*cont].telefone,TesteTelefone);
    printf("Email: ");
    scanf(" %s", (*agenda)[*cont].email);
    (*cont)++;
    
    printf("Contato adicionado!\n");
}

void printContatos(contato *agenda, int cont){
    printf("\nAgenda:\n\n");
    for (int i = 0; i < cont; i++) {
        printf("Contato %d\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Email: %s\n", agenda[i].email);
        printf("-----------------------\n");
    }
}

void searchContatos(contato *agenda, int cont){
    char searchName[30];
    int find = 0;
    printf("\nDigite o nome desejado\n");
    printf("Nome: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < cont; i++){
        if(strcmp(agenda[i].nome,searchName)== 0)
        {   
            printf("\nContato:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("-----------------------\n");
            find = 1;
        }
    }

    if(!find)
        printf("Contato nao encontrado");
}

void deleteContato(contato *agenda, int *cont){
  char searchName[30];
  int find = 0;
  printf("\nPesquisar Nome a ser Deletado:");
  scanf(" %[^\n]", searchName);

  for(int i = 0; i < *cont; i++){
    if(strcmp(searchName,agenda[i].nome) == 0)
    {
      for(int j = i; j < *cont - 1; j++)
      {
        agenda[j] = agenda[j+1];
      }
      (*cont)--;
      printf("O contato foi removido!\n");
      find = 1;
      return;
    }
  }

  if(!find)
        printf("Contato nao encontrado\n");
}