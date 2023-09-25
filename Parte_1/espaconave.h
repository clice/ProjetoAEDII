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

struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos);
void trocarEspaconaves(struct Espaconave **a, struct Espaconave **b);

#endif // ESPACONAVE_H
