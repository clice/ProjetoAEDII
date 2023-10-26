#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "lista.h"
#include "hash_table.h"

int main()
{
    int opcao = 20, i, teste, id;
    char escolha;
    Lista tabela[20];

    printf("---------------------------------------------------------\n\n");
    printf("\nSeja Bem-Vindo(a) ao Acompanhamento das Naves 5000\n");
    printf("Da Big D.O.G Corporation\n");
    printf("\nSo sera possivel a expansao se houver 6 naves com o\n");
    printf("mesmo recurso so que em combinacoes diferentes\n\n");
    printf("---------------------------------------------------------\n\n");

    inicializarHashTable(tabela);

    while (opcao != 0) {
        imprimirHashTable(tabela);

        printf("\n\t---------------------------------------------------------\n");
        printf("\n\t0 - Sair");
        printf("\n\t1 - Atualizar a lista");
        printf("\n\t2 - Verificar se e possivel fazer a expansao da entrada");
        printf("\n\t3 - Exemplo com leitura de arquivo");
        printf("\n\tInforme a opcao: ");
        scanf("%d", &opcao);
        printf("\n\t---------------------------------------------------------\n\n");

        // Caso queira atualizar a lista de espaçonaves (gera automaticamente)
        if (opcao == 1) {
            // Gera automaticamente 10 espaçonaves
            for (i = 0; i < 200; i++) { // Alterar para diminuir a quantidade de inserções
                char recurso[4];
                // Gera a sequência de recursos das espaçonaves
                gerarSequenciaAleatoria(recurso);
                // Identifica a hash de cada recurso gerado
                id = funcaoHash(calcularID(recurso));

                // Verifica se a hash é válida e se sim insere na hash table
                if (verificarRepeticao(&tabela[id], recurso) == 0) {
                    inserirNaHashTable(tabela, recurso);
                }
            }
        }
        // Caso queira verificar se é possível realizar a expansão da passagem
        else if (opcao == 2) {
            verificarExpansaoPassagem(tabela);
        }
        // Caso queira testar um exemplo de expansão
        else if (opcao == 3) {
            arquivoRecursos(tabela);
        }
        // Caso informe uma opção inválida
        else{
            printf("CALMA GUERREIRO, SO TEM 4 OPCOES");
            sleep(5);
        }
    }

    return 0;
}
