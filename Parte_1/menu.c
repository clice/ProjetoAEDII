#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "espaconave.h"

// FUNÇÃO PARA INICIALIZAR O SISTEMA DE PRIORIZAR NAVES
int inicializarSistema()
{
    int opcao;
    printf("SISTEMA DE FILA DE PRIORIDADES DE ESPACONAVES\n\n");

    while(1) {
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
                exit(1);
                break;

            case 1:
                arquivoEspaconaves();
                break;

            default:
                printf("OPCAO INVALIDA!\n\n");
                break;
        }
    }
}
