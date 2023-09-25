#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"
#include "espaconave.h"
// #include "passageiro.h"
// #include "recurso.h"

// FUNÇÃO PARA CRIAR UM HEAP PARA ARMAZENAR AS ESPAÇONAVES
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap)); // Aloca memória para o Heap
    heap->capacidade = capacidade; // Define a capacidade máxima do Heap
    heap->tamanho = 0; // Inicializa o tamanho do Heap com 0
    heap->naves = (struct Espaconave **)malloc(capacidade * sizeof(struct Espaconave *)); // Aloca memória para as naves
    return heap;
}

// FUNÇÃO PARA CRIAR UMA NOVA ESPAÇONAVE
struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos)
{
    struct Espaconave *nave = (struct Espaconave *)malloc(sizeof(struct Espaconave)); // Aloca memória para o Heap de espaçonaves
    nave->prioridade = prioridade; // Define a prioridade da espaçonave
    nave->qtdPassageiros = qtdPassageiros; // Define a quantidade de passageiros na espaçonave
    nave->qtdRecursos = qtdRecursos; // Define a quantidade de recursos na espaçonave
    nave->passageiros = NULL; // Inicializa o ponteiro de passageiros vazio
    nave->recursos = NULL; // Inicializa o ponteiro de recursos vazio
    // nave->passageiros = (struct Passageiro *)malloc(qtdPassageiros * sizeof(struct Passageiro)); // Aloca memória para os passageiros
    // nave->recursos = (struct Recurso *)malloc(qtdRecursos * sizeof(struct Recurso)); // Aloca memória para os recursos
    return nave;
}

// FUNÇÃO PARA TROCAR AS NAVES
void trocarEspaconaves(struct Espaconave **a, struct Espaconave **b) {
    struct Espaconave *temp = *a;
    *a = *b;
    *b = temp;
}

// // FUNÇÃO PARA LER O ARQUIVO COM AS INFORMAÇÕES INICIAIS DAS ESPACONAVES
// void arquivoEspaconaves()
// {
//     int prioridade;

//     // Abre o arquivo em modo de leitura
//     FILE *arquivo = fopen("espaconaves.txt", "r");

//     // Verifica se o arquivo foi aberto com sucesso
//     if (arquivo == NULL) {
//         printf("Nao foi possivel abrir o arquivo %s.\n", "naves.txt");
//         return 1;
//     }

//     // Lê os números do arquivo e os imprime na tela
//     while (fscanf(arquivo, "%d", &prioridade) != EOF) {
//         printf("Inserir: %d\n", prioridade);

//         struct Espaconave *nave = criarEspaconave(prioridade, );
//         // inserir(heap, numero);
//         // imprimirHeap(heap);
//     }

//     // Fecha o arquivo após a leitura
//     fclose(arquivo);

//     return 0;
// }

//// FUNÇÃO PARA INSERIR UMA ESPAÇONAVE NO HEAP
//void inserirEspaconave(struct Heap *heap, struct Espaconave *nave) {
//    if (heap->tamanho == heap->capacidade) {
//        printf("O Heap está cheio. Não é possível inserir mais espaçonaves.\n");
//        return;
//    }
//
//    int indice = heap->tamanho;
//    heap->naves[indice] = nave;
//    heap->tamanho++;
//
//    // Corrige o MaxHeap para manter a propriedade de MaxHeap
//    while (indice > 0 && heap->naves[(indice - 1) / 2] < heap->naves[indice]) {
//        trocar(&heap->naves[(indice - 1) / 2], &heap->naves[indice]);
//        indice = (indice - 1) / 2;
//    }
//}
