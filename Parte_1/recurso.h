#ifndef RECURSO_H
#define RECURSO_H

// ESTRUTURA PARA REPRESENTAR O RECURSO
struct Recurso
{
    char nomeRecurso[15]; // Nome do recurso  
    struct Recurso *prox; // Ponteiro para o próximo recurso
};

char *escolherNomeRecursoAleatorio();

#endif // RECURSO_H