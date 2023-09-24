#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUN��O PARA CRIAR UM NOVO HEAP
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));// Aloca mem�ria para o Heap
    heap->capacidade = capacidade; // Define a capacidade m�xima do Heap
    heap->tamanho = 0; // Inicializa o tamanho do Heap com 0
    heap->naves = (struct Nave *)malloc(capacidade * sizeof(struct Nave)); // Aloca mem�ria para as naves
    return heap;
}

// FUN��O PARA TROCAR NAVES
void trocarNaves(struct Nave *a, struct Nave *b)
{
    struct Nave temp = *a;  // Cria uma c�pia tempor�ria da nave 'a'
    *a = *b;                // Atribui os valores da nave 'b' � nave 'a'
    *b = temp;              // Atribui os valores da c�pia tempor�ria � nave 'b'
}
