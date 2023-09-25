#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "espaconave.h"
// #include "passageiro.h"
// #include "recurso.h"

// FUNÇÃO PARA CRIAR UM HEAP PARA ARMAZENAR AS ESPAÇONAVES
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap)); // Aloca memória para o Heap
    heap->capacidade = capacidade; // Define a capacidade máxima do Heap
    heap->tamanho = 0; // Inicializa o tamanho do Heap com 0
    heap->naves = (struct Espaconave *)malloc(capacidade * sizeof(struct Espaconave)); // Aloca memória para as naves
    return heap;
}

// FUNÇÃO PARA CRIAR UMA NOVA ESPAÇONAVE
struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos)
{
    struct Espaconave *nave = (struct Espaconave *)malloc(sizeof(struct Espaconave)); // Aloca memória para o Heap de espaçonaves
    nave->prioridade = prioridade; // Define a prioridade da espaçonave
    nave->qtdPassageiros = qtdPassageiros; // Define a quantidade de passageiros na espaçonave
    nave->qtdRecursos = qtdRecursos; // Define a quantidade de recursos na espaçonave
    nave->passageiros = NULL; // Inicializa o ponteiro de passageiros vazio
    nave->recursos = NULL; // Inicializa o ponteiro de recursos vazio
    return nave;
}

// FUNÇÃO PARA TROCAR AS ESPAÇONAVES
void trocarEspaconaves(struct Espaconave *a, struct Espaconave *b) {
    struct Espaconave *temp = a;
    a = b;
    b = temp;
}

// FUNÇÃO PARA ORGANIZAR O HEAP APÓS A INSERÇÃO OU REMOÇÃO DE UMA ESPAÇONAVE
void organizarHeap(struct Heap *heap, int index)
{
    int maior = index;
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;

    if (esquerda < heap->tamanho && heap->naves[esquerda].prioridade > heap->naves[maior].prioridade) maior = esquerda;

    if (direita < heap->tamanho && heap->naves[direita].prioridade > heap->naves[maior].prioridade) maior = direita;

    if (maior != index) {
        trocarEspaconaves(&heap->naves[index], &heap->naves[maior]);
        organizarHeap(heap, maior);
    }
}

// FUNÇÃO PARA INSERIR UMA NOVA ESPAÇONAVE NO HEAP
void inserirEspaconave(struct Heap *heap, struct Espaconave *nave, int prioridade, int qtdPassageiros, int qtdRecursos)
{
    // Checando se o Heap está cheio
    if (heap->tamanho == heap->capacidade) { // Se o tamanho (quantidade ocupada) com a capacidade (quantidade total)
        printf("O fila de naves esta cheia. Nao eh possivel inserir mais naves.\n");
        return;
    }

    struct Espaconave *novaEspaconave = criarEspaconave(prioridade, qtdPassageiros, qtdRecursos);
    int i = heap->tamanho; // Valor para ser usado no laço
    heap->tamanho++; // Adicionar um ao tamanho para ocupar o espaço da nova espaçonave

    //
    while (i > 0 && heap->naves[(i - 1) / 2].prioridade < heap->naves[i].prioridade) {
        trocarEspaconaves(&heap->naves[i], &heap->naves[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// // FUNÇÃO PARA REMOVER A ESPAÇONAVE COM MAIOR PRIORIDADE DO HEAP
// struct Espaconave *removerEspaconave(struct Heap *heap)
// {
//     if (heap->tamanho <= 0) return NULL;

//     if (heap->tamanho == 1) {
//         heap->tamanho--;
//         return heap->naves[0];
//     }

//     struct Espaconave *raiz = heap->naves[0];
//     heap->naves[0] = heap->naves[heap->tamanho - 1];
//     heap->tamanho--;

//     organizarHeap(heap, 0);

//     return raiz;
// }

// // FUNÇÃO PARA IMPRIMIR AS ESPAÇONAVES DO HEAP
// void imprimirHeap(struct Heap *heap)
// {
//     printf("ESPAÇONAVES:\n");
//     for (int i = 0; i < heap->tamanho; i++) {
//         printf("%d", *(heap->naves[i].prioridade));
//     }
//     printf("\n");
// }

// FUNÇÃO PARA LER O ARQUIVO COM AS INFORMAÇÕES INICIAIS DAS ESPACONAVES
void arquivoEspaconaves()
{
    int prioridade;

    // Abre o arquivo em modo de leitura
    FILE *arquivo = fopen("espaconaves.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s.\n", "naves.txt");
        return 1;
    }

    // Lê os números do arquivo e os imprime na tela
    while (fscanf(arquivo, "%d", &prioridade) != EOF) {
        printf("Inserir: %d\n", prioridade);

        struct Espaconave *nave = criarEspaconave(10, 10, 10);
        // inserir(heap, numero);
        // imprimirHeap(heap);
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);

    return 0;
}

//// FUNÇÃO PARA INSERIR UMA ESPAÇONAVE NO HEAP
//void inserirEspaconave(struct Heap *heap, struct Espaconave *nave) {
//    if (heap->tamanho == heap->capacidade) {
//        printf("O Heap está cheio. Não é possível inserir mais espaçonaves.\n");
//        return;
//    }
//
//    int indice = heap->tamanho;
//    heap->naves[indice] = nave;
//    heap->tamanho++;
//
//    // Corrige o MaxHeap para manter a propriedade de MaxHeap
//    while (indice > 0 && heap->naves[(indice - 1) / 2] < heap->naves[indice]) {
//        trocar(&heap->naves[(indice - 1) / 2], &heap->naves[indice]);
//        indice = (indice - 1) / 2;
//    }
//}
