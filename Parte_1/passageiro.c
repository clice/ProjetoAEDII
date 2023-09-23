#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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