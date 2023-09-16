#include "heap.h"
#include <stdio.h>

int main() {
    struct Heap *heap = criarHeap(10);
    printf("Heap: \n");
    imprimirHeap(heap);

    return 0;
}