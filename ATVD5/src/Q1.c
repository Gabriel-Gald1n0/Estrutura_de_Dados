#include "biblioteca1.h"

int main(){
    Expressao *ex = NULL;
    int opcao = 0;
    char palavra[81];
    int maxCap, size = 0, n = 0;

    do{ 
        printf("Digite a capacidade maxima da lista: ");
        scanf("%d", &maxCap);
        if(0 < maxCap && maxCap <= 100) break;
        else
            printf("Digite um tamanho entre 0 e 100!!!\n");
    } while (1);
    
    do{
        printf("1 - Consultar\n2 - Exibir Ordem Crescente \n3 - Exibir Ordem Decrescente\n4 - Historico\n5 - Encerrar\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1: //Consultar
            printf("Digite uma palavra: ");
            scanf(" %[^\n]",palavra);
            consultar(&ex, palavra, maxCap, &size);
            int pos = cont(ex, palavra);
            printf("A expressao esta na posicao: %d\n", pos);
            break;
        case 2: //Exibir Ordem Crescente 
            imprimeCrescente(ex);
            break;
        case 3: //Exibir Ordem Decrescente 
            imprimeDecrescente(ex);
            break;
        case 4: //Historico
            printf("Veja as Ultimas N consultas: ");
            scanf("%d",&n);
            if(n < 0) {
                printf("Digite um valor positivo\n");
                break;
            }
            historico(ex,n);
            break;
        case 5: // Encerrar 
            libera(&ex);
            printf("Programa Encerrado");
            break;
        
        default:
            printf("Opcao invalida");
            break;
        }
    }while(opcao != 5);
}

