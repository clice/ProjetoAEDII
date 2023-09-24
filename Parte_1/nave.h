#ifndef NAVE_H
#define NAVE_H

// ESTRUTURA PARA REPRESENTAR A NAVE
struct Nave
{
    int prioridade;                      // Valor da prioridade da nase
    int qtdPassageiros;                  // Quantidade de passageiros
    struct Passageiro *listaPassageiros; // Lista de passageiros
    struct Recurso *listaRecursos;       // Lista de recursos
};

#endif // NAVE_H
