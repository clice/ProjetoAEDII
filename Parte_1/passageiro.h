#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

// ESTRUTURA PARA REPRESENTAR O PASSAGEIRO
struct Passageiro
{
    int id;                     // Identificador único
    char nome[15];              // Nome do passageiro
    int idade;                  // Idade do passageiro
    char planeta[15];           // Planeta de origem do passageiro
    struct Passageiro *prox;    // Ponteiro para o próximo passageiro na lista
};

int escolherQtdPassageirosAleatoria();
char *escolherNomeAleatorio();
int escolherIdadeAleatoria();
char *escolherPlanetaAleatorio();
int selecionarPassageirosNave();

#endif // PASSAGEIRO_H