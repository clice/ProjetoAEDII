#ifndef LISTA_H
#define LISTA_H

// ESTRUTURA PARA REPRESENTAR A LISTA DE NAVES
typedef struct No {
    char sequencia[4];  // Array de recursos
    int chave;          //
    struct No *proximo; // Link para o pr�ximo n�
} No;

// ESTRUTURA PARA REPRESENTAR A LISTA DE NAVES
typedef struct Lista {
    No *inicio;  //
    int tam;     // Tamanho da lista de espa�onaves
} Lista;

void inicializarLista(Lista *l);
void inserirNaLista(Lista *l, char recursos[4]);
int buscarNaLista(Lista *l, int valor);
void imprimirNaLista(Lista *l);

int verificaRepeticao(Lista *l, char recurso[4]);

#endif // LISTA_H
