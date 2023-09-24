#ifndef ESPACONAVE_H
#define ESPACONAVE_H

// ESTRUTURA PARA REPRESENTAR A ESPACONAVE
struct Espaconave
{
    int prioridade;                      // Valor da prioridade da nase
    int qtdPassageiros;                  // Quantidade de passageiros
    int qtdRecursos;                     // Quantidade de recursos
    struct Passageiro *passageiros;      // Lista de passageiros
    struct Recurso *recursos;            // Lista de recursos
};

void arquivoEspaconaves();
struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos, struct Passageiro *passageiros);

#endif // ESPACONAVE_H
