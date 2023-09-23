#ifndef HEAP_H
#define HEAP_H

// ESTRUTURA PARA REPRESENTAR O HEAP
struct Heap
{
    int *arr;
    int tamanho;
    int capacidade;
};

//
struct Heap * criarHeap(int capacidade);
void imprimirHeap(struct Heap * heap);
void inserir(struct Heap *heap, int valor);
void heapify(struct Heap *heap, int index);

#endif // HEAP_H
