#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "hash_table.h"

// FUN��O PARA INICIALIZAR A LISTA DE ESPA�ONAVES
void inicializarLista(Lista *l)
{
    l->inicio = NULL;  // Define o inicio da lista como NULL (lista est� vazia)
    l->tam = 0;        // Define o tamanho da lista como zero
}

// FUN��O PARA INSERIR RECURSOS NA LISTA DE RECURSOS DE UMA ESPA�ONAVE PARA O HASH TABLE
void inserirNaLista(Lista *l, char recursos[4])
{
    No *novo = malloc(sizeof(No)); // Aloca mem�ria para um novo n� da lista

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (novo) {
        // Copia os recursos fornecidos para o campo do novo n�
        for (int i = 0; i < 4; i++) {
            novo->sequencia[i] = recursos[i];
        }

        novo->proximo = l->inicio; // O novo n� aponta para o antigo in�cio da lista
        l->inicio = novo;          // Atualiza o in�cio da lista para apontar para o novo n�
        l->tam++;                  // Incrementa o tamanho da lista
    } else {
        // Caso a aloca��o de mem�ria tenha falhado, exibe uma mensagem de erro
        printf("\n\tErro ao alocar memoria!\n");
    }
}

//
int buscarNaLista(Lista *l, int valor)
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o in�cio da lista

    // Percorre a lista enquanto o ponteiro auxiliar n�o for nulo e
    // o valor da chave do n� atual n�o for igual ao valor procurado
    while (aux && aux->chave != valor) aux = aux->proximo;

    // Verifica se o valor foi encontrado na lista
    // Se o ponteiro auxiliar n�o � nulo, significa que o valor foi encontrado,
    // e a fun��o retorna a chave do n� encontrado
    // Caso contr�rio, se o valor n�o foi encontrado, a fun��o retorna 0
    // para indicar que o valor n�o existe na lista.
    if (aux) return aux->chave;
    else return 0;
}

//
void imprimirLista(Lista *l)
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o in�cio da lista

    printf(" Tam: %d: ", l->tam); // Imprime o tamanho da lista

    // Loop para percorrer a lista e imprimir seus elementos
    while (aux) {
        // Imprime os recursos da nave (a sequ�ncia) do n� atual
        printf("Recursos da nave: %s\n", aux->sequencia);

        // Move o ponteiro auxiliar para o pr�ximo n� na lista
        aux = aux->proximo;
    }
}

//
int verificaRepeticao(Lista *l, char recurso[4])
{
    No *aux = l->inicio; // Inicializa um ponteiro auxiliar para o in�cio da lista

    // Percorre a lista enquanto o ponteiro auxiliar n�o for nulo e
    // a sequ�ncia do n� atual for diferente do recurso procurado.
    while (aux && (strcmp(aux->sequencia, recurso) != 0)) aux = aux->proximo;

    // Verifica se a sequ�ncia foi encontrada na lista
    // Se o ponteiro auxiliar n�o � nulo, significa que a sequ�ncia foi encontrada,
    // e a fun��o retorna 1 para indicar que houve repeti��o
    // Caso contr�rio, se a sequ�ncia n�o foi encontrada,
    // a fun��o retorna 0 para indicar que n�o houve repeti��o
    if (aux) return 1;
    else return 0;
}

// FUN��O PARA VERIFICAR O TAMANHO DO HASH TABLE
int verificarTamanhoHashTable(Lista t[])
{
    int tamanho = 0;

    for (int i = 0; i < 20; i++) {
        tamanho = verificarTamanhoLista(&t[i]);
        if (tamanho == 6) break; // Quando tiver encontrado um caso com 6 sai do la�o
    }

    return(tamanho);
}

// FUN��O PARA VERIFICAR O TAMANHO DE CADA LISTA DO HASH TABLE
int verificarTamanhoLista(Lista *l)
{
    No *aux = l->inicio; // Ponteiro para o in�cio da lista

    // La�o para percorrer cada lista de cada posi��o da Hash Table
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
