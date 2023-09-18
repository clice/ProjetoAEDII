#ifndef LISTADEFOGUETES_H_INCLUDED
#define LISTADEFOGUETES_H_INCLUDED

//Dados
struct Nave{
    char nome[50];
    int chave;
};

struct Fila{
     Nave *dados;
     int tam,n;
};

//funções

*Fila fila_criar(int tam);
void destruir_fila(Fila **f);
void adicionar_nave(Fila *f,Nave x);
Nave entrar_no_portal(Fila *f);

int Fila_cheia(Fila *f);
int Fila_vazia(Fila *f);

