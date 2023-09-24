#ifndef HEAP_H
#define HEAP_H

// ESTRUTURA PARA O HEAP
struct Heap {
    int tamanho;        // O tamanho atual do Heap (n�mero total de elementos no Heap)
    int capacidade;     // A capacidade m�xima do Heap (n�mero m�ximo de elementos no Heap)
    struct Nave *naves; // Um ponteiro para o array de naves
};

#endif // HEAP_H
