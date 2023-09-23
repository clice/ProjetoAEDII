#define HEAP_H_INCLUDED
#define F_esq(i) (2*i+1)
#define F_dir(i) (2*i+2)
#define PAI(i)
#define swap(a,b) {Nave tmp=*a; *a=*b ;*b=tmp;}


<<<<<<< HEAD
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
=======


>>>>>>> 5e58219ebf4b90778ed2ccdbbc0b5aeef4336d4a
