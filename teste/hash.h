#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "espaconave.h"

#endif // HASH_H_INCLUDED

typedef struct{
    No *inicio;
    int tam;
}Lista;



void iniciaLista(Lista *l);

void iniciaTabela(int t[]);

int funcaoHash(int chave);

void inserir(int t[], int valor[]);

void busca(int t[], int chave[]);

void imprimir(int t[]);

