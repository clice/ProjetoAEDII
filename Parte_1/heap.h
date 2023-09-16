#ifndef HEAP_H
#define HEAP_H

struct Heap {
    int *arr;
    int tamanho;
    int capacidade;
};

struct Heap* criarHeap(int capacidade);
void imprimirHeap(struct Heap *heap);

#endif