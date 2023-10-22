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
    Lista tabela[20];

    printf("\nSeja Bem-Vindo(a) ao Acompanhamento das Naves 5000 Da Big D.O.G Corporation\n");
    printf("\nSo sera possivel a expansao se houver 6 naves com o mesmo recurso so que em combinacoes diferentes\n\n");

    inicializarHashTable(tabela);

    while (opcao != 0) {
        imprimirHashTable(tabela);

        printf("\n\t0 - Sair");
        printf("\n\t1 - Atualizar a lista");
        printf("\n\t2 - Verificar se e possivel fazer a Expansao da entrada");
        printf("\n\t3 - Exemplo com leitura de arquivo");
        printf("\n\tInforme a opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            for (i = 0; i < 10; i++) {
                char recurso[4];
                gerarSequenciaAleatoria(recurso);
                id = funcaoHash(calcularID(recurso));

                if (verificarRepeticao(&tabela[id], recurso) == 0) {
                    inserirNaHashTable(tabela, recurso);
                }
            }
        }
        else if (opcao == 2) {
            teste = verificarTamanhoHashTable(tabela);

            if (teste == 6) {
                printf("\n Deseja estocar na Abertura?[Y/N] \n");
            } else if (teste == 0) {
                printf("\n Nao e estocar expandir a Abertura \n");
            }
        } else if (opcao == 3) {
            printf("-------------------------------------------------------------------------------------------\n\n");
            printf("LENDO O ARQUIVO DA LISTA DE RECURSOS...\n\n");

            // Abre o arquivo em modo de leitura
            FILE *arquivo = fopen("recursos.txt", "r");

            // Verifica se o arquivo foi aberto com sucesso
            if (arquivo == NULL) {
                printf("Nao foi possivel abrir o arquivo %s.\n", "recursos.txt");
                printf("-------------------------------------------------------------------------------------------\n\n");
                break;
            } else {
                // Vetor de ponteiros para armazenar os recursos lidas
                char **linhas = NULL;
                size_t numLinhas = 0;

                // Buffer para armazenar a linha lida
                char linha[5]; // Defina o tamanho apropriado para o seu caso

                // Loop para ler e armazenar cada linha do arquivo
                while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                        // Remove o caracter de nova linha '\n'
                    size_t len = strlen(linha);
                    if (len > 0 && linha[len - 1] == '\n') {
                        linha[len - 1] = '\0';
                    }

                    // Aloca espaço para a linha lida e copia-a para o vetor
                    char *novaLinha = strdup(linha); // Requer #include <string.h>
                    linhas = (char **)realloc(linhas, (numLinhas + 1) * sizeof(char *));
                    linhas[numLinhas] = novaLinha;

                    numLinhas++;
                }

                // Fecha o arquivo após a leitura
                fclose(arquivo);

                // Exibe os recursos armazenadas
                for (size_t i = 0; i < numLinhas; i++) {
                    id = funcaoHash(calcularID(linhas[i]));

                    if (verificarRepeticao(&tabela[id], linhas[i]) == 0) {
                        inserirNaHashTable(tabela, linhas[i]);
                    }

                    free(linhas[i]); // Libera a memória alocada para cada linha
                }

                printf("\nARQUIVO LIDO COM SUCESSO! Lista de recursos adicionada.\n\n");
            }
        }
    }

    return 0;
}
