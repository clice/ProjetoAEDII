#include <stdio.h>
#include <stdlib.h>
#include "Filadefoguetes.h"
#include "heap.h"
#define F_esq(i) (2*i+1)
#define F_dir(i) (2*i+2)
#define PAI(i)
#define swap(a,b) {Nave tmp=*a; *a=*b ;*b=tmp;}




// FUN��O PARA CRIAR O HEAP
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->arr = (int *)malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

// FUN��O PARA IMPRIMIR O HEAP
void imprimirHeap(struct Heap *heap)
{
    for (int i = 0; i < heap->tamanho; i++) {
        printf("%d ", heap->arr[i]);
    }

    printf("\n");
}

// FUN��O AUXILIAR DE TROCA DE ELEMENTOS DE POSI��O
void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// FUN��O PARA INSERIR INFORMA��ES NO HEAP
void inserir(struct Heap *heap, int valor)
{
    int index;

    if (heap->tamanho == heap->capacidade) {
        printf("O Heap esta cheio. Nao eh poss�vel inserir outros elementos.\n");
        return;
    }

    heap->tamanho++;
    index = heap->tamanho - 1;
    heap->arr[index] = valor;

    while (index != 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        troca(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// FUN��O PARA ORGANIZAR O HEAP COM AS PRIORIDADES
void heapify(struct Heap *heap, int index)
{
    int maior = index;
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;

    //
    if (esquerda < heap->tamanho && heap->arr[esquerda] > heap->arr[maior]) maior = esquerda;

    //
    if (direita < heap->tamanho && heap->arr[direita] > heap->arr[maior]) maior = direita;

    //
    if (maior != index) {
        troca(&heap->arr[index], &heap->arr[maior]);
        heapify(heap, maior);
    }
}
