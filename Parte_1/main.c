#include <stdio.h>
#include <stdlib.h>

#include "espaconave.h"

// DECLARAÇÃO DAS FUNÇÕES DO MENU
void inicializarSistema();

int main()
{
    inicializarSistema();
    return 0;
}

// FUNÇÃO PARA INICIALIZAR O SISTEMA DE PRIORIZAR NAVES
void inicializarSistema()
{
    int c, opcao;
    struct Heap *heap;

    while(1) {
        printf("---------------------------------------------------------\n\n");
        printf("SEJA BEM-VINDO(A) AO SISTEMA DE FILA DE PRIORIDADES DE\n");
        printf("ESPACONAVES DA BIG D.O.G CORPORATION\n\n");
        printf("---------------------------------------------------------\n\n");
        printf("ESCOLHA UMA DAS OPCOES:\n");
        printf("1 - Inicializar o sistema de fila de prioridades\n");
        printf("2 - Finalizar programa\n\n");
        printf("Informe a opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        // Switch do menu de inicialização
        switch (opcao) {
            // Caso queira inicializar a fila de prioridades das espaçonaves
            case 1:
                heap = arquivoEspaconaves();
                if (heap == NULL) break;
                else gerenciarHeap(heap);
                system("cls");
                break;

            // Caso queira finalizar o programa
            case 2:
                printf("---------------------------------------------------------\n\n");
                printf("A BIG D.O.G CORPORATION AGRADECE A PREFERENCIA!\n\n");
                printf("FIM DA EXECUCAO!\n\n");
                printf("---------------------------------------------------------\n");
                exit(1);
                break;

            // Caso a opção informada não esteja na lista
            default:
                printf("OPCAO INVALIDA!\n\n");
                while ((c = getchar()) != '\n' && c != EOF); // Limpar a entrada do buffer
                system("pause");
                system("cls");
                break;
        }

    }
}
