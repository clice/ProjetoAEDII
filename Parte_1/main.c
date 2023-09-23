#include "heap.h"
#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int main() {
//     struct MaxHeap *heap = criarHeap(10);

//     inserir(heap, 10);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 20);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 15);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 40);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 50);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 30);

//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);

//     return 0;
// }

// int main() {
//     int numero;
//     FILE *arquivo;
//     char nomeArquivo[] = "numeros.txt"; // Substitua pelo nome do seu arquivo
//     struct Heap *heap = criarHeap(10);

//     // Abre o arquivo em modo de leitura
//     arquivo = fopen(nomeArquivo, "r");

//     // Verifica se o arquivo foi aberto com sucesso
//     if (arquivo == NULL) {
//         printf("Não foi possível abrir o arquivo %s.\n", nomeArquivo);
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

// FUNÇÃO PARA ADICIONAR UM PASSAGEIRO A LISTA
struct Passageiro *adicionarPassageiro(struct Passageiro *cabeca, int id) {
    struct Passageiro *novoPassageiro = (struct Passageiro *)malloc(sizeof(struct Passageiro));

    if (novoPassageiro == NULL) {
        printf("Erro ao alocar memória para o novo passageiro.\n");
        exit(1);
    }

    novoPassageiro->id = id; // Usando um ID aleatório como exemplo
    strcpy(novoPassageiro->nome, escolherNomeAleatorio()); // Nome aleatório da lista
    novoPassageiro->idade = escolherIdadeAleatoria(); // Idade aleatória entre 1 e 100
    strcpy(novoPassageiro->planeta, escolherPlanetaAleatorio()); // Planeta de origem aleatório da lista

    novoPassageiro->prox = cabeca; // O próximo passageiro na lista é a cabeça atual
    return novoPassageiro; // O novo passageiro se torna a nova cabeça da lista
}

// FUNÇÃO PARA IMPRIMIR OS PASSAGEIROS DA NAVE
void imprimirPassageiros(struct Passageiro *cabeca) {
    struct Passageiro *atual = cabeca;

    while (atual != NULL) {
        printf("Identificador: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);
        printf("Planeta de origem: %s\n", atual->planeta);
        printf("\n");

        atual = atual->prox;
    }
}

int main() {
    int i = 0, qtdPassageiros = escolherQtdPassageirosAleatoria();
    struct Passageiro *listaPassageiros = NULL; // Inicialmente, a lista está vazia

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    printf("Quantidade de passageiros: %d\n", qtdPassageiros);

    for (i = 0; i < qtdPassageiros; i++) {
        // Adicionando passageiros à lista
        listaPassageiros = adicionarPassageiro(listaPassageiros, i);
    }

    // Imprimindo os passageiros na lista
    imprimirPassageiros(listaPassageiros);

    // Liberando a memória alocada para os passageiros
    while (listaPassageiros != NULL) {
        struct Passageiro *temp = listaPassageiros;
        listaPassageiros = listaPassageiros->prox;
        free(temp);
    }

    return 0;
}
