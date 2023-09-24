#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "recurso.h"
#include "passageiro.h"
#include "espaconave.h"

// void arquivoEspaconaves()
// {
//     int numero;
//     struct Heap *heap = criarHeap(10);

//     // Abre o arquivo em modo de leitura
//     FILE *arquivo = fopen("naves.txt", "r");

//     // Verifica se o arquivo foi aberto com sucesso
//     if (arquivo == NULL) {
//         printf("Nao foi possivel abrir o arquivo %s.\n", "naves.txt");
//         return 1;
//     }

//     // Lê os números do arquivo e os imprime na tela
//     while (fscanf(arquivo, "%d", &numero) != EOF) {
//         printf("Inserir: %d\n", numero);
//         inserir(heap, numero);
//         imprimirHeap(heap);
//     }

//     // Fecha o arquivo após a leitura
//     fclose(arquivo);

//     return 0;
// }

// Função para criar uma nova espaçonave
struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos, struct Passageiro *passageiro, struct Recurso *recursos)
{
    struct Espaconave *nave = (struct Espaconave *)malloc(sizeof(struct Espaconave)); // Aloca memória para o Heap de espaçonaves
    nave->prioridade = prioridade; // Define a prioridade da espaçonave
    nave->qtdPassageiros = qtdPassageiros; // Define a quantidade de passageiros na espaçonave
    nave->qtdRecursos = qtdRecursos; // Define a quantidade de recursos na espaçonave
    nave->passageiros = (struct Passageiro *)malloc(qtdPassageiros * sizeof(struct Passageiro)); // Aloca memória para os passageiros
    nave->recursos = (struct Recurso *)malloc(qtdRecursos * sizeof(struct Recurso)); // Aloca memória para os recursos 
    return nave;
}
