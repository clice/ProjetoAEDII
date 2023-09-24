#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    *b = temp;              // Atribui os valores da cópia temporária à nave 'b'
}
