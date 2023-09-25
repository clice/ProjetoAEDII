#include "menu.h"
#include <stdio.h>

int main() {
    inicializarSistema();
}

// #include <stdio.h>
// #include <stdlib.h>

// // Estrutura de um n� do MaxHeap
// typedef struct {
//     int *data; // O dado (um ponteiro para um n�mero inteiro neste caso)
//     int priority; // A prioridade (o valor inteiro associado ao ponteiro)
// } MaxHeapNode;

// // Estrutura do MaxHeap
// typedef struct {
//     MaxHeapNode **array; // Array de ponteiros para os n�s do heap
//     int capacity; // Capacidade m�xima do heap
//     int size; // Tamanho atual do heap
// } MaxHeap;

// // Fun��o para criar um novo n� do MaxHeap
// MaxHeapNode* createMaxHeapNode(int *data, int priority) {
//     MaxHeapNode* newNode = (MaxHeapNode*)malloc(sizeof(MaxHeapNode));
//     newNode->data = data;
//     newNode->priority = priority;
//     return newNode;
// }

// // Fun��o para criar um novo MaxHeap
// MaxHeap* createMaxHeap(int capacity) {
//     MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
//     maxHeap->capacity = capacity;
//     maxHeap->size = 0;
//     maxHeap->array = (MaxHeapNode**)malloc(capacity * sizeof(MaxHeapNode*));
//     return maxHeap;
// }

// // Fun��o para trocar dois n�s
// void swapMaxHeapNode(MaxHeapNode** a, MaxHeapNode** b) {
//     MaxHeapNode* temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Fun��o para ajustar o MaxHeap ap�s a inser��o de um novo n�
// void maxHeapify(MaxHeap* maxHeap, int idx) {
//     int largest = idx;
//     int left = 2 * idx + 1;
//     int right = 2 * idx + 2;

//     if (left < maxHeap->size && maxHeap->array[left]->priority > maxHeap->array[largest]->priority)
//         largest = left;

//     if (right < maxHeap->size && maxHeap->array[right]->priority > maxHeap->array[largest]->priority)
//         largest = right;

//     if (largest != idx) {
//         swapMaxHeapNode(&maxHeap->array[idx], &maxHeap->array[largest]);
//         maxHeapify(maxHeap, largest);
//     }
// }

// // Fun��o para inserir um novo n� no MaxHeap
// void insertMaxHeap(MaxHeap* maxHeap, int *data, int priority) {
//     if (maxHeap->size == maxHeap->capacity) {
//         printf("O heap est� cheio. N�o � poss�vel inserir mais elementos.\n");
//         return;
//     }

//     MaxHeapNode* newNode = createMaxHeapNode(data, priority);
//     int i = maxHeap->size;
//     maxHeap->size++;

//     maxHeap->array[i] = newNode;

//     while (i > 0 && maxHeap->array[(i - 1) / 2]->priority < maxHeap->array[i]->priority) {
//         swapMaxHeapNode(&maxHeap->array[i], &maxHeap->array[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
// }

// // Fun��o para extrair o n� com maior prioridade (raiz) do MaxHeap
// MaxHeapNode* extractMax(MaxHeap* maxHeap) {
//     if (maxHeap->size <= 0)
//         return NULL;

//     if (maxHeap->size == 1) {
//         maxHeap->size--;
//         return maxHeap->array[0];
//     }

//     MaxHeapNode* root = maxHeap->array[0];
//     maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
//     maxHeap->size--;

//     maxHeapify(maxHeap, 0);

//     return root;
// }

// // Fun��o para imprimir os elementos do MaxHeap
// void printMaxHeap(MaxHeap* maxHeap) {
//     printf("Elementos do MaxHeap: ");
//     for (int i = 0; i < maxHeap->size; i++) {
//         printf("%d ", *(maxHeap->array[i]->data));
//     }
//     printf("\n");
// }

// // Fun��o principal
// int main() {
//     MaxHeap* maxHeap = createMaxHeap(10);

//     int data1 = 10;
//     int data2 = 5;
//     int data3 = 15;

//     insertMaxHeap(maxHeap, &data1, 10);
//     insertMaxHeap(maxHeap, &data2, 5);
//     insertMaxHeap(maxHeap, &data3, 15);

//     printMaxHeap(maxHeap);

//     MaxHeapNode* maxNode = extractMax(maxHeap);
//     if (maxNode != NULL) {
//         printf("Elemento com a maior prioridade: %d\n", *(maxNode->data));
//     }

//     printMaxHeap(maxHeap);

//     return 0;
// }
