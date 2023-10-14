#ifndef ESPACONAVE_H
#define ESPACONAVE_H

// ESTRUTURA PARA REPRESENTAR A ESPACONAVE
struct Espaconave
{
    int prioridade;                  // Valor da prioridade da nase
    int qtdPassageiros;              // Quantidade de passageiros
    int qtdRecursos;                 // Quantidade de recursos
    struct Passageiro *passageiros;  // Lista de passageiros
    struct Recurso *recursos;        // Lista de recursos
};

// ESTRUTURA PARA O HEAP
struct Heap
{
    int tamanho;                // O tamanho atual do Heap (número total de elementos no Heap)
    int capacidade;             // A capacidade máxima do Heap (número máximo de elementos no Heap)
    struct Espaconave **naves;  // Lista de naves
};

struct Heap *criarHeap(int capacidade);
void organizarHeap(struct Heap *heap, int index);
void imprimirHeap(struct Heap *heap);
void gerenciarHeap(struct Heap *heap);

struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos);
void trocarEspaconaves(struct Espaconave **a, struct Espaconave **b);
void inserirEspaconave(struct Heap *heap, int prioridade, int qtdPassageiros, int qtdRecursos);
struct Espaconave *removerEspaconave(struct Heap *heap);
struct Heap *arquivoEspaconaves();
int imagemEspaconave();

#endif // ESPACONAVE_H
