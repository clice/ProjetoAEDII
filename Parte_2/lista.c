#include <stdio.h>
#include <stdlib.h>

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

//
void imprimirLista(Lista *l)
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o início da lista

    printf(" Tam: %d: ", l->tam); // Imprime o tamanho da lista

    // Loop para percorrer a lista e imprimir seus elementos
    while (aux) {
        // Imprime os recursos da nave (a sequência) do nó atual
        printf("Recursos da nave: %s\n", aux->sequencia);

        // Move o ponteiro auxiliar para o próximo nó na lista
        aux = aux->proximo;
    }
}

//
int verificaRepeticao(Lista *l, char recurso[4])
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o início da lista

    // Percorre a lista enquanto o ponteiro auxiliar não for nulo e
    // a sequência do nó atual for diferente do recurso procurado.
    while (aux && (strcmp(aux->sequencia, recurso) != 0)) aux = aux->proximo;

    // Verifica se a sequência foi encontrada na lista
    // Se o ponteiro auxiliar não é nulo, significa que a sequência foi encontrada,
    // e a função retorna 1 para indicar que houve repetição
    // Caso contrário, se a sequência não foi encontrada,
    // a função retorna 0 para indicar que não houve repetição
    if (aux) return 1;
    else return 0;
}

// FUNÇÃO PARA VERIFICAR O TAMANHO DO HASH TABLE
int verificarTamanhoHashTable(Lista t[])
{
    int tamanho = 0;

    for (int i = 0; i < 20; i++) {
        tamanho = verificarTamanhoLista(&t[i]);
        if (tamanho == 6) break; // Quando tiver encontrado um caso com 6 sai do laço
    }

    return(tamanho);
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

        printf("???");
        aux = aux->proximo;
    }

    return 0;
}
