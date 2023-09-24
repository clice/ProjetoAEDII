#ifndef HEAP_H
#define HEAP_H

// ESTRUTURA PARA O HEAP
struct Heap {
    int tamanho;        // O tamanho atual do Heap (n�mero total de elementos no Heap)
    int capacidade;     // A capacidade m�xima do Heap (n�mero m�ximo de elementos no Heap)
    struct Nave *naves; // Lista de naves
};

struct Heap *criarEspaconave(int capacidade);
void trocarEspaconaves(struct Nave *a, struct Nave *b);

#endif // HEAP_H
