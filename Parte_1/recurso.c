#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "recurso.h"

// FUNÇÃO PARA GERAR UMA QUANTIDADE DE RECURSOS
int gerarQtdRecursos()
{
    return (rand() % 100) + 1; // Gera um número aleatório para quantidade de recursos na espaçonave
}

// FUNÇÃO PARA GERAR UM NOME DE RECURSO ALEATÓRIO
char *gerarNomeRecurso()
{
    // Lista de nomes de recursos
    char *nomesRecursos[] = {
        "Água", "B", "Carvao", "D", "E", "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "Ouro", "Petróleo", "Q", "R", "S", "T",
        "U", "V", "W", "X", "Y", "Z"
    };

    int numNomes = sizeof(nomesRecursos) / sizeof(nomesRecursos[0]); // Cálculo da quantidade de elementos do vetor
    int indice = rand() % numNomes; // Escolhe um índice aleatório da lista de nomes dos recursos
    return nomesRecursos[indice];
}

//
int inicializarRecursos()
{
    return 0;
}
