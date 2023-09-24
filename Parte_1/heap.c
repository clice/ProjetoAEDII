#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"
#include "espaconave.h"

// FUNÇÃO PARA CRIAR UM NOVO HEAP
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));// Aloca memória para o Heap
    heap->capacidade = capacidade; // Define a capacidade máxima do Heap
    heap->tamanho = 0; // Inicializa o tamanho do Heap com 0
    heap->naves = (struct Nave *)malloc(capacidade * sizeof(struct Nave)); // Aloca memória para as naves
    return heap;
}

// FUNÇÃO PARA TROCAR NAVES
void trocarNaves(struct Nave *a, struct Nave *b)
{
    struct Nave temp = *a;  // Cria uma cópia temporária da nave 'a'
    *a = *b;                // Atribui os valores da nave 'b' à nave 'a'
    *b = temp;              // Atribui os valores da cópia temporária da nave 'b'
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NO HEAP
void inserir(struct Heap *heap, int elemento) {
    if (maxHeap->tamanho == maxHeap->capacidade) {
        printf("O MaxHeap está cheio. Não é possível inserir mais elementos.\n");
        return;
    }

    int indice = maxHeap->tamanho;
    maxHeap->arr[indice] = elemento;
    maxHeap->tamanho++;

    // Corrige o MaxHeap para manter a propriedade de MaxHeap
    while (indice > 0 && maxHeap->arr[(indice - 1) / 2] < maxHeap->arr[indice]) {
        trocar(&maxHeap->arr[(indice - 1) / 2], &maxHeap->arr[indice]);
        indice = (indice - 1) / 2;
    }
}

// Função para inserir uma nave no Heap
void inserirNave(struct Heap *heap, int prioridade, const char *nome) {
    if (heap->tamanho >= heap->capacidade) {
        printf("O Heap está cheio. Não é possível inserir mais naves.\n");
        return;
    }

    int indice = heap->tamanho;
    heap->tamanho++;

    heap->naves[indice].prioridade = prioridade;
    strcpy(heap->naves[indice].nome, nome);

    // Corrige o Heap para manter a propriedade de Heap de Min
    while (indice > 0 && heap->naves[(indice - 1) / 2].prioridade > heap->naves[indice].prioridade) {
        trocar(&heap->naves[(indice - 1) / 2], &heap->naves[indice]);
        indice = (indice - 1) / 2;
    }
}