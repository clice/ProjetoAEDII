//#include "heap.h"
#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// FUNÇÃO PARA ADICIONAR UM PASSAGEIRO A LISTA
struct Passageiro *adicionarPassageiro(struct Passageiro *cabeca, int id) {
    struct Passageiro *novoPassageiro = (struct Passageiro *)malloc(sizeof(struct Passageiro));

    if (novoPassageiro == NULL) {
        printf("Erro ao alocar memória para o novo passageiro.\n");
        exit(1);
    }

    novoPassageiro->id = rand(); // Usando um ID aleatório como exemplo
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
