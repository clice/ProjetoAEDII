#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "hash_table.h"

int funcaoHash(int chave)
{
    switch (chave) {
    case 111:
        return 0;
    case 1011:
        return 1;
    case 10011:
        return 2;
    case 100011:
        return 3;
    case 1101:
        return 4;
    case 10101:
        return 5;
    case 100101:
        return 6;
    case 11001:
        return 7;
    case 101001:
        return 8;
    case 110001:
        return 9;
    case 1110:
        return 10;
    case 10110:
        return 11;
    case 100110:
        return 12;
    case 11010:
        return 13;
    case 101010:
        return 14;
    case 110010:
        return 15;
    case 11100:
        return 16;
    case 101100:
        return 17;
    case 110100:
        return 18;
    case 111000 :
        return 19;
    }
}

void inicializarHashTable(Lista t[])
{
    for (int i = 0; i < 20; i++) inicializarLista(&t[i]);
}

void inserirNaHashTable(Lista t[],char recurso[4])
{
    int id = funcaoHash(calcularID(recurso));
    inserir_na_lista(&t[id], recurso);
}

int buscarNaHashTable(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}
