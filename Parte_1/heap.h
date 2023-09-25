#ifndef HEAP_H
#define HEAP_H

// ESTRUTURA PARA O HEAP
struct Heap {
    int tamanho;                // O tamanho atual do Heap (número total de elementos no Heap)
    int capacidade;             // A capacidade máxima do Heap (número máximo de elementos no Heap)
    struct Espaconave **naves;   // Lista de naves
};

struct Heap *criarHeap(int capacidade);
// void trocarEspaconaves(struct Nave *a, struct Nave *b);

#endif // HEAP_H
