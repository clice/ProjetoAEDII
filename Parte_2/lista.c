#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "hash_table.h"

// FUNÇÃO PARA INICIALIZAR A LISTA DE ESPAÇONAVES
void inicializarLista(Lista *l)
{
    l->inicio = NULL;  // Define o inicio da lista como NULL (lista está vazia)
    l->tam = 0;        // Define o tamanho da lista como zero
}

// FUNÇÃO PARA INSERIR RECURSOS NA LISTA DE RECURSOS DE UMA ESPAÇONAVE PARA O HASH TABLE
void inserirNaLista(Lista *l, char recursos[4])
{
    No *novo = malloc(sizeof(No)); // Aloca memória para um novo nó da lista

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo) {
        // Copia os recursos fornecidos para o campo do novo nó
        for (int i = 0; i < 4; i++) {
            novo->sequencia[i] = recursos[i];
        }

        novo->proximo = l->inicio; // O novo nó aponta para o antigo início da lista
        l->inicio = novo;          // Atualiza o início da lista para apontar para o novo nó
        l->tam++;                  // Incrementa o tamanho da lista
    } else {
        // Caso a alocação de memória tenha falhado, exibe uma mensagem de erro
        printf("\n\tErro ao alocar memoria!\n");
    }
}

//
int buscarNaLista(Lista *l, int valor)
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o início da lista

    // Percorre a lista enquanto o ponteiro auxiliar não for nulo e
    // o valor da chave do nó atual não for igual ao valor procurado
    while (aux && aux->chave != valor) aux = aux->proximo;

    // Verifica se o valor foi encontrado na lista
    // Se o ponteiro auxiliar não é nulo, significa que o valor foi encontrado,
    // e a função retorna a chave do nó encontrado
    // Caso contrário, se o valor não foi encontrado, a função retorna 0
    // para indicar que o valor não existe na lista.
    if (aux) return aux->chave;
    else return 0;
}

// FUNÇÃO PARA IMPRIMIR A LISTA COM OS RECURSOS DAS ESPAÇONAVES
void imprimirLista(Lista *l)
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o início da lista

    printf(" Tam: %d: \n", l->tam); // Imprime o tamanho da lista

    // Loop para percorrer a lista e imprimir seus elementos
    while (aux) {
        // Imprime os recursos da nave (a sequência) do nó atual
        printf("Recursos da nave: %s\n", aux->sequencia);

        // Move o ponteiro auxiliar para o próximo nó na lista
        aux = aux->proximo;
    }
}

void limparLista(Lista *l)
{
    No *aux = l->inicio;

    while (aux) {
        l->tam = 0;
        l->inicio = NULL;
        aux = aux->proximo;
    }
}

// FUNÇÃO PARA VERIFICAR A REPETIÇÃO DOS RECURSOS
int verificarRepeticao(Lista *l, char recurso[4])
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o in�cio da lista

    // Percorre a lista enquanto o ponteiro auxiliar n�o for nulo e
    // a sequ�ncia do n� atual for diferente do recurso procurado.
    while (aux && (strcmp(aux->sequencia, recurso) != 0)) aux = aux->proximo;

    // Verifica se a sequ�ncia foi encontrada na lista
    // Se o ponteiro auxiliar n�o � nulo, significa que a sequ�ncia foi encontrada,
    // e a fun��o retorna 1 para indicar que houve repeti��o
    // Caso contr�rio, se a sequ�ncia n�o foi encontrada,
    // a função retorna 0 para indicar que n�o houve repeti��o
    if (aux) return 1;
    else return 0;
}

// FUNÇÃO PARA VERIFICAR O TAMANHO DE CADA LISTA DO HASH TABLE
int verificarTamanhoLista(Lista *l)
{
    No *aux = l->inicio; // Ponteiro para o início da lista

    // Laço para percorrer cada lista de cada posição da Hash Table
    while (aux){
        if (l->tam == 6) {
            return 6;
            break;
        }
        aux = aux->proximo;
    }

    return 0;
}

//
void arquivo(Lista tabela[])
{
    int id;
    char **linhas = NULL;
    size_t numLinhas = 0;

    printf("\nLendo o arquivo da lista de recursos...\n\n");

    // Buffer para armazenar a linha lida
    char linha[5]; // Defina o tamanho apropriado para o seu caso

    // Abre o arquivo em modo de leitura
    FILE *arquivo = fopen("recursos.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s.\n", "recursos.txt");
        printf("---------------------------------------------------------\n\n");
        //break;
    } else {
        // Loop para ler e armazenar cada linha do arquivo
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            // Remove o caracter de nova linha '\n'
            // size_t é um tipo de dado mesmo que 'int' não sinalizado
            // usado para armazenar o retorno de uma operação sizeof
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

        printf("\nArquivo lido com sucesso! Lista de recursos adicionada.\n\n");
    }

    // Exibe os recursos armazenadas
    for (size_t i = 0; i < numLinhas; i++) {
        id = funcaoHash(calcularID(linhas[i]));

        if (verificarRepeticao(&tabela[id], linhas[i]) == 0) {
            inserirNaHashTable(tabela, linhas[i]);
        }

        free(linhas[i]); // Libera a memória alocada para cada linha
    }

    if (verificarTamanhoHashTable(tabela) == 6) {
        printf("\nQuantidade de recursos atingiu a quantidade maxima! PORTAL SE ABRIU!\n");
        printf("\nLIMPEZA NECESSARIA!\n\n");
        // limparHashTable(tabela);
        inicializarHashTable(tabela);
    }
}
