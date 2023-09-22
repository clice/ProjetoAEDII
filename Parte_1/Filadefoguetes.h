#define LISTADEFOGUETES_H_INCLUDED

//Dados
typedef struct {
    char nome[50];
    int chave;
}Nave;

typedef struct {
     Nave *dados;
     int tam,n;
}Fila;

//funções

Fila* fila_criar(int tam);
void destruir_fila(Fila **f);
void adicionar_nave(Fila *f,Nave x);
Nave entrar_no_portal(Fila *f);

int Fila_cheia(Fila *f);
int Fila_vazia(Fila *f);

