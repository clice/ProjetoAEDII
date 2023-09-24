#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "passageiro.h"

// FUNÇÃO PARA ESCOLHER A QUANTIDADE DE PASSAGEIROS DA NAVE
int escolherQtdPassageirosAleatoria()
{
	int qtdAleatoria = (rand() % 20) + 1; // Gera um número aleatório para a quantidade de passageiros
	return qtdAleatoria;
}

// FUNÇÃO PARA ESCOLHER UM NOME ALEATÓRIO PARA UM PASSAGEIRO
char *escolherNomeAleatorio()
{
    // Lista de nomes de passageiros
    char *nomes[] = {
        "Arthur", "Bilbo", "Chewbacca", "Draco", "Eva", "Frodo", "Ginny", "Harry", "Ikari", "Joker",
        "Kenobi", "Luke", "Marvin", "Nazgul", "Organa", "Percy", "Queen", "Rony", "Samwise", "Trillian",
        "Umbridge", "Voldemort", "Wick", "Xavier", "Yoda", "Zaphod"
    };

    int numNomes = sizeof(nomes) / sizeof(nomes[0]); // Cálculo da quantidade de elementos do vetor
    int indice = rand() % numNomes; // Escolhe um índice aleatório da lista de nomes
    return nomes[indice];
}

// FUNÇÃO PARA ESCOLHER UMA IDADE ALEATÓRIA PARA UM PASSAGEIRO
int escolherIdadeAleatoria()
{
    int idadeAleatoria = (rand() % 100) + 1; // Gera um número aleatório para a idade do passageiro
    return idadeAleatoria;
}

// FUNÇÃO PARA ESCOLHER UM NOME DE PLANETA ALEATÓRIA PARA O PASSAGEIRO
char *escolherPlanetaAleatorio()
{
    // Lista de nomes de planetas
    char *planetas[] = {
        "Arrakis", "Biblioteca", "Coruscant", "Discworld", "Eden", "F", "Gallifrey", "Hogwarts", "Isengard", "Jupiter",
        "Krypton", "Lothlorien", "Magrathea", "Netuno", "Omega", "Pandora", "Quimera", "R", "Skaro", "Tatooine",
        "Urano", "Vulcano", "Westeros", "X", "Y", "Zion"
    };

    int numPlanetas = sizeof(planetas) / sizeof(planetas[0]); // Cálculo da quantidade de elementos do vetor
    int indice = rand() % numPlanetas; // Escolhe um índice aleatório da lista de planetas
    return planetas[indice];
}



// FUNÇÃO PARA ADICIONAR UM PASSAGEIRO A LISTA
struct Passageiro *adicionarPassageiro(struct Passageiro *cabeca, int id) 
{
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
void imprimirPassageiros(struct Passageiro *cabeca)
{
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

int inicializarPassageiros()
{
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