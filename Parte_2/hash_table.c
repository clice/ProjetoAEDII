#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "hash_table.h"

int funcaoHash(int chave)
{
    switch (chave) {
        case 111:
            return 0;
            break;

        case 1011:
            return 1;
            break;

        case 10011:
            return 2;
            break;

        case 100011:
            return 3;
            break;

        case 1101:
            return 4;
            break;

        case 10101:
            return 5;
            break;

        case 100101:
            return 6;
            break;

        case 11001:
            return 7;
            break;

        case 101001:
            return 8;
            break;

        case 110001:
            return 9;
            break;

        case 1110:
            return 10;
            break;

        case 10110:
            return 11;
            break;

        case 100110:
            return 12;
            break;

        case 11010:
            return 13;
            break;

        case 101010:
            return 14;
            break;

        case 110010:
            return 15;
            break;

        case 11100:
            return 16;
            break;

        case 101100:
            return 17;
            break;

        case 110100:
            return 18;
            break;

        case 111000 :
            return 19;
            break;
    }

    return -1;
}

// Funcao para calcular a soma dos valores associados as letras na sequência
int calcularID(char sequencia[4])
{
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

void inicializarHashTable(Lista t[])
{
    for (int i = 0; i < 20; i++) inicializarLista(&t[i]);
}

void inserirNaHashTable(Lista t[], char recurso[4])
{
    int id = funcaoHash(calcularID(recurso));
    inserirNaLista(&t[id], recurso);
}

int buscarNaHashTable(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    return buscarNaLista(&t[id], chave);
}

// FUN��O PARA VERIFICAR O TAMANHO DO HASH TABLE
int verificarTamanhoHashTable(Lista t[])
{
    int tamanho = 0;

    for (int i = 0; i < 20; i++) {
        tamanho = verificarTamanhoLista(&t[i]);
        if (tamanho == 6) break; // Quando tiver encontrado um caso com 6 sai do laço
    }

    return tamanho;
}

void imprimirHashTable(Lista t[])
{
    for (int i = 0; i < 20; i++) {
        printf("%2d = ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

// FUNÇÃO PARA LIMPAR A HASH TABLE
void limparHashTable(Lista t[]) {
    for (int i = 0; i < 20; i++) {
        free(&t[i]);
    }
}

char gerarLetraAleatoria(char letrasUsadas[], int tamanho)
{
    char letrasRestantes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int letrasRestantesCount = 6 - tamanho;
    int indiceAleatorio = rand() % letrasRestantesCount;

    for (int i = 0; i < tamanho; i++) {
        if (letrasUsadas[i] == letrasRestantes[indiceAleatorio]) {
            // Se a letra já foi usada, ajusta o índice aleatório
            indiceAleatorio = (indiceAleatorio + 1) % letrasRestantesCount;
            i = -1; // Volta ao início do loop para verificar novamente
        }
    }

    return letrasRestantes[indiceAleatorio];
}

// Funcao para gerar uma sequ�ncia de tr�s letras aleat�rias sem repeti��es
void gerarSequenciaAleatoria(char sequencia[4])
{
    char letrasUsadas[3] = {0}; // Inicializa com zeros

    for (int i = 0; i < 3; i++) {
        sequencia[i] = gerarLetraAleatoria(letrasUsadas, i);
        letrasUsadas[i] = sequencia[i];
    }

    sequencia[3] = '\0'; // Adiciona um caractere nulo para criar uma string v�lida
}
