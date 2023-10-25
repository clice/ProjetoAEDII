#ifndef HASH_TABLE_H
#define HASH_TABLE_H

int funcaoHash(int chave);
int calcularID(char sequencia[4]);

void inicializarHashTable(Lista t[]);
void inserirNaHashTable(Lista t[], char recurso[4]);
int buscarNaHashTable(Lista t[], int chave);
int verificarTamanhoHashTable(Lista t[]);
void imprimirHashTable(Lista t[]);
void limparHashTable(Lista t[]);

char gerarLetraAleatoria(char letrasUsadas[], int tamanho);
void gerarSequenciaAleatoria(char sequencia[4]);

void imprimirTristeza();

#endif // HASH_TABLE_H
