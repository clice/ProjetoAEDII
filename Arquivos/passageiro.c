#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// FUN��O PARA ESCOLHER QUANTIDADE DE PASSAGEIROS DA NAVE
int escolherQtdPassageirosAleatoria()
{
    int qtdAleatoria = (rand() % 20) + 1; // Gera um n�mero aleat�rio para a quantidade de passageiros
    return qtdAleatoria;
}

// FUN��O PARA ESCOLHER UM NOME ALEAT�RIO PARA UM PASSAGEIRO
char *escolherNomeAleatorio()
{
    // Lista de nomes de passageiros
    char *nomes[] = {
        "Arthur", "Bilbo", "Chewbacca", "Draco", "Eva", "Frodo", "Ginny", "Harry", "Ikari", "Joker",
        "Kenobi", "Luke", "Marvin", "Nazgul", "Organa", "Percy", "Queen", "Rony", "Samwise", "Trillian",
        "Umbridge", "Voldemort", "Wick", "Xavier", "Yoda", "Zaphod"
    };

    int numNomes = sizeof(nomes) / sizeof(nomes[0]); // C�lculo da quantidade de elementos do vetor
    int indice = rand() % numNomes; // Escolhe um �ndice aleat�rio da lista de nomes
    return nomes[indice];
}

// FUN��O PARA ESCOLHER UMA IDADE ALEAT�RIA PARA UM PASSAGEIRO
int escolherIdadeAleatoria()
{
    int idadeAleatoria = (rand() % 100) + 1; // Gera um n�mero aleat�rio para a idade do passageiro
    return idadeAleatoria;
}

// FUN��O PARA ESCOLHER UM NOME DE PLANETA ALEAT�RIA PARA O PASSAGEIRO
char *escolherPlanetaAleatorio()
{
    // Lista de nomes de planetas
    char *planetas[] = {
        "Arrakis", "Biblioteca", "Coruscant", "Discworld", "Eden", "F", "Gallifrey", "Hogwarts", "Isengard", "Jupiter",
        "Krypton", "Lothlorien", "Magrathea", "Netuno", "Omega", "Pandora", "Quimera", "R", "Skaro", "Tatooine",
        "Urano", "Vulcano", "Westeros", "X", "Y", "Zion"
    };

    int numPlanetas = sizeof(planetas) / sizeof(planetas[0]); // C�lculo da quantidade de elementos do vetor
    int indice = rand() % numPlanetas; // Escolher um �ndice aleat�rio da lista de planetas
    return planetas[indice];
}

//int selecionarPassageirosNave()
//{
//   int i = 0, qtdPassageiros = escolherQtdPassageirosAleatoria();
//    struct Passageiro *listaPassageiros = NULL; // Inicialmente, a lista est� vazia
//
//    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios
//
//    printf("Quantidade de passageiros: %d\n", qtdPassageiros);
//
//    for (i = 0; i < qtdPassageiros; i++) {
//        // Adicionando passageiros � lista
//        listaPassageiros = adicionarPassageiro(listaPassageiros, i);
//    }
//
//    // Imprimindo os passageiros na lista
//    imprimirPassageiros(listaPassageiros);
//
//    // Liberando a mem�ria alocada para os passageiros
//    while (listaPassageiros != NULL) {
//        struct Passageiro *temp = listaPassageiros;
//        listaPassageiros = listaPassageiros->prox;
//        free(temp);
//    }
//
//    return 0;
//}
