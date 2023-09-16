#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

// FUNÇÃO PARA CRIAR O HEAP
struct Heap *criarHeap(int capacidade) {
    struct Heap *heap = (struct Heap *) malloc(sizeof(struct Heap));
    heap->arr = (int *) malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

// FUNÇÃO PARA IMPRIMIR O HEAP
void imprimirHeap(struct Heap *heap) {
    printf("Heap: ");

    for (int i = 0; i < heap->tamanho; i++) {
        print("%d ", heap->arr[i]);
    }

    printf("\n");
}