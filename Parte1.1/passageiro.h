#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

// ESTRUTURA PARA REPRESENTAR O PASSAGEIRO
struct Passageiro
{
    int id;                     // Identificador único
    char nome[15];              // Nome do passageiro
    int idade;                  // Idade do passageiro
    char planeta[15];           // Planeta de origem do passageiro
    struct Passageiro *prox;    // Ponteiro para o próximo passageiro
};

char *gerarNome();
int gerarIdade();
char *gerarPlaneta();
int gerarQtdPassageiros();
struct Passageiro *adicionarPassageiro(struct Passageiro *cabeca, int id);
void imprimirPassageiros(struct Passageiro *cabeca);
int inicializarPassageiros();

#endif // PASSAGEIRO_H