#include <stdio.h>
#include <stdlib.h>

#include "espaconave.h"

// FUNÇÃO PARA INICIALIZAR O SISTEMA DE PRIORIZAR NAVES
void inicializarSistema()
{
    int opcao;
    struct Heap *heap;

    printf("-----------------------------------------------------------------------\n\n");
    printf("SISTEMA DE FILA DE PRIORIDADES DE ESPACONAVES\n\n");

    while(1) {
        printf("-----------------------------------------------------------------------\n\n");
        printf("ESCOLHA UMA DAS OPCOES:\n");
        printf("1 - Inicializar o sistema de fila de prioridades\n");
        printf("0 - Finalizar programa\n\n");
        printf("Informe a opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        // Switch do menu de inicialização
        switch (opcao) {
            case 0:
                printf("FIM DA EXECUCAO!\n\n");
                printf("-----------------------------------------------------------------------\n");
                exit(1);
                break;

            case 1:
                heap = arquivoEspaconaves();
                if (heap == NULL) break;
                else gerenciamentoEspaconaves(heap);
                break;

            default:
                printf("OPCAO INVALIDA!\n\n");
                break;
        }
    }
}




// DECLARAÇÃO DAS FUNÇÕES DO MENU
void inicializarSistema();

int main() {
    inicializarSistema();
    return 0;
}


