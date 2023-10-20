#ifndef ESPACONAVE_H_INCLUDED
#define ESPACONAVE_H_INCLUDED





typedef struct no{
    char sequencia[4];
    int chave;
    struct no *proximo;
}No;

typedef struct lista{
    No *inicio;
    int tam;
}Lista;


void inicializarLista(Lista *l);

void inserir_na_lista(Lista *l,char recursos[4]);

int buscar_na_lista(Lista *l, int valor);

void imprimir_lista(Lista *l);

void inicializarTabela(Lista t[]);

int funcaoHash(int chave);

int verificaRepeticao(Lista *l,char recurso[4]);

void inserir(Lista t[],char recurso[4]);

int busca(Lista t[], int chave);

void imprimir(Lista t[]);

int calcularPosicao(char sequencia[4]);

void gerarRecurso(char sequencia[4]);

char gerarRecursoAleatoria(char letrasUsadas[], int tamanho);
char* generateRandomLetters();


int verificarTamanho(Lista t[]);

int Verifica_Tam(Lista *l);
#endif // ESPACONAVE_H_INCLUDED

