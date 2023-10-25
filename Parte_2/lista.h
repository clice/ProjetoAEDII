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
    int tam;     // Tamanho da lista de espaçonaves
} Lista;

void inicializarLista(Lista *l);
void inserirNaLista(Lista *l, char recursos[4]);
int buscarNaLista(Lista *l, int valor);
void imprimirLista(Lista *l);
void limparLista(Lista *l);

int verificarRepeticao(Lista *l, char recurso[4]);
int verificarTamanhoLista(Lista *l);

#endif // LISTA_H
