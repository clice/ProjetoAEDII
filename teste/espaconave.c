#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Lista de nomes de navios brasileiros
const char* nomeNave[] = {
    "Atl�ntico",
    "Brasil",
    "Cisne Branco",
    "Amazonas",
    "Tamandar�",
    "Aruana",
    "Baependi",
    "Cruzeiro do Sul",
    "Imperial Marinheiro",
    "Vital de Oliveira",
    "Riachuelo",
    "Almirante Barroso",
    "Bahia",
    "Independ�ncia",
    "Greenhalgh",
    "Bosisio",
    "Constitui��o",
    "Get�lio Vargas",
    "Minas Gerais",
    "Barroso"
};

// Fun��o para gerar um nome de navio aleat�rio
const char* gerarNomeDeNave() {
    int num_nomes = sizeof(nomeNave) / sizeof(nomeNave[0]);
    int indice_aleatorio = rand() % num_nomes;
    return nomeNave[indice_aleatorio];
}


// Fun��o para gerar uma letra aleat�ria entre A e F, sem repeti��es
char gerarLetraAleatoria(char letrasUsadas[], int tamanho) {
    char letrasRestantes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int letrasRestantesCount = 6 - tamanho;

    int indiceAleatorio = rand() % letrasRestantesCount;

    for (int i = 0; i < tamanho; i++) {
        if (letrasUsadas[i] == letrasRestantes[indiceAleatorio]) {
            // Se a letra j� foi usada, ajusta o �ndice aleat�rio
            indiceAleatorio = (indiceAleatorio + 1) % letrasRestantesCount;
            i = -1; // Volta ao in�cio do loop para verificar novamente
        }
    }

    return letrasRestantes[indiceAleatorio];
}

// Fun��o para calcular a soma dos valores associados �s letras na sequ�ncia
int calcularSomaSequencia(char sequencia[4]) {
    int valores[6] = {1, 10, 100, 1000, 10000, 100000};
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        switch (sequencia[i]) {
            case 'A':
                soma += valores[0];
                break;
            case 'B':
                soma += valores[1];
                break;
            case 'C':
                soma += valores[2];
                break;
            case 'D':
                soma += valores[3];
                break;
            case 'E':
                soma += valores[4];
                break;
            case 'F':
                soma += valores[5];
                break;
        }
    }

    return soma;
}


// Fun��o para gerar uma sequ�ncia de tr�s letras aleat�rias sem repeti��es
void gerarSequenciaAleatoria(char sequencia[4]) {
    char letrasUsadas[3] = {0}; // Inicializa com zeros
    for (int i = 0; i < 3; i++) {
        sequencia[i] = gerarLetraAleatoria(letrasUsadas, i);
        letrasUsadas[i] = sequencia[i];
    }
    sequencia[3] = '\0'; // Adiciona um caractere nulo para criar uma string v�lida
}


//cria espa�onave
struct Espaconave *criarEspaconave(char nome[], char recurso[])
{
    struct Espaconave *nave = (struct Espaconave *)malloc(sizeof(struct Espaconave)); // Aloca mem�ria para o Heap de espa�onaves
    nave->nome=nome[];
    nave->recurso=recurso[];


    return nave;
}


void inserir Espaconave
