#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "espaconave.h"
#include "passageiro.h"
#include "recurso.h"

////////// FUNÇÕES DO HEAP

// FUNÇÃO PARA CRIAR UM HEAP PARA ARMAZENAR AS ESPAÇONAVES
struct Heap *criarHeap(int capacidade)
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap)); // Aloca memória para o Heap
    heap->capacidade = capacidade; // Define a capacidade máxima do Heap
    heap->tamanho = 0; // Inicializa o tamanho do Heap com 0
    heap->naves = (struct Espaconave **)malloc(capacidade * sizeof(struct Espaconave*)); // Aloca memória para as naves
    return heap;
}

// FUNÇÃO PARA ORGANIZAR O HEAP APÓS A REMOÇÃO DE UMA ESPAÇONAVE
void organizarHeap(struct Heap *heap, int index)
{
    int maior = index; // Inicializa o índice da nave de maior prioridade como inicial
    int esquerda = 2 * index + 1; // Calcula o índice da nave à esquerda da maior
    int direita = 2 * index + 2; // Calcula o índice da nave à direita da maior

    // Verifica se a nave à esquerda (filho) existe e tem prioridade maior que a nave atual (pai)
    if (esquerda < heap->tamanho && heap->naves[esquerda]->prioridade > heap->naves[maior]->prioridade) maior = esquerda;

    // Verifica se a nave à direita (filho) existe e tem prioridade maior que a nave atual (pai)
    if (direita < heap->tamanho && heap->naves[direita]->prioridade > heap->naves[maior]->prioridade) maior = direita;

    // Se a maior nave não for a nave atual
    if (maior != index) {
        trocarEspaconaves(&heap->naves[index], &heap->naves[maior]); // Troca a posição das naves
        organizarHeap(heap, maior); // Organiza o Heap das naves (chamada recursiva)
    }
}

// FUNÇÃO PARA IMPRIMIR AS INFORMAÇÕES DAS ESPAÇONAVES DO HEAP
void imprimirHeap(struct Heap *heap)
{
    printf("ESPACONAVES:\n");
    for (int i = 0; i < heap->tamanho; i++) {
        printf("Prioridade: %d\n", heap->naves[i]->prioridade);
        printf("Qtd de Passageiros: %d\n", heap->naves[i]->qtdPassageiros);
        printf("Qtd de Recursos: %d\n", heap->naves[i]->qtdRecursos);
        printf("\n");
    }
}

// FUNÇÃO PARA GERENCIAR DO HEAP
void gerenciarHeap(struct Heap *heap)
{
    int opcao, prioridade;

    while(1) {
        printf("-----------------------------------------------------------------------\n\n");
        printf("GERENCIAMENTO DA FILA DE ESPACONAVES\n\n");
        printf("ESCOLHA UMA DAS OPCOES:\n");
        printf("1 - Adicionar um nova espaconave\n");
        printf("2 - Remover uma espaconave\n");
        printf("3 - Imprimir informacoes das espaconaves\n\n");
        printf("Informe a opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        // Switch do menu
        switch (opcao) {
            case 1:
                printf("Informe a prioridade da nave: ");
                scanf("%d", &prioridade);

                // Gerar porcentagem para cálculo da prioridade
                int porcento = rand() % 9;

                if (porcento == 1){ // Cálculo 10% de chance
                    prioridade = (rand() % 100) + 1;
                    printf("\nPRIORIDADE ALTERADA PARA %d! A nave pode ter uma possivel contaminacao!\n\n", prioridade);
                    inserirEspaconave(heap, prioridade, gerarQtdPassageiros(), gerarQtdRecursos());
                    break;
                } else {
                    inserirEspaconave(heap, prioridade, gerarQtdPassageiros(), gerarQtdRecursos());
                    break;
                }

            case 2:
                removerEspaconave(heap);
                break;

            case 3:
                imprimirHeap(heap);
                break;

            default:
                break;
        }
    }
}

////////// FUNÇÕES DAS ESPAÇONAVES

// FUNÇÃO PARA CRIAR UMA NOVA ESPAÇONAVE
struct Espaconave *criarEspaconave(int prioridade, int qtdPassageiros, int qtdRecursos)
{
    struct Espaconave *nave = (struct Espaconave *)malloc(sizeof(struct Espaconave)); // Aloca memória para o Heap de espaçonaves
    nave->prioridade = prioridade; // Define a prioridade da espaçonave
    nave->qtdPassageiros = qtdPassageiros; // Define a quantidade de passageiros na espaçonave
    nave->qtdRecursos = qtdRecursos; // Define a quantidade de recursos na espaçonave
    nave->passageiros = NULL; // Inicializa o ponteiro de passageiros vazio
    nave->recursos = NULL; // Inicializa o ponteiro de recursos vazio
    return nave;
}

// FUNÇÃO PARA TROCAR AS ESPAÇONAVES
void trocarEspaconaves(struct Espaconave **a, struct Espaconave **b) {
    struct Espaconave *temp = *a; // Variável temporária para uma nave 'temp' recebe nave 'a'
    *a = *b; // Nave 'a' recebe Nave 'b'
    *b = temp; // Nave 'b' recebe a variável temporária
}

// FUNÇÃO PARA INSERIR UMA NOVA ESPAÇONAVE NO HEAP
void inserirEspaconave(struct Heap *heap, int prioridade, int qtdPassageiros, int qtdRecursos)
{
    // Verifica se o heap atingiu sua capacidade máxima
    if (heap->tamanho == heap->capacidade) { // Se o tamanho (quantidade ocupada) com a capacidade (quantidade total)
        printf("O fila de naves esta cheia. Nao eh possivel inserir mais naves.\n");
        return;
    }

    // Cria uma nova espaçonave com a prioridade, quantidade de passageiros e quantidade de recursos informada
    struct Espaconave *novaNave = criarEspaconave(prioridade, qtdPassageiros, qtdRecursos);
    int i = heap->tamanho; // Valor para ser usado no laço, onde a nova espaçonave será inserida
    heap->naves[i] = novaNave; // Insere uma nova espaçonave no Heap
    heap->tamanho++; // Aumenta o tamanho do Heap após a inserção

    // Realiza o ajuste para manter a propriedade do Heap
    // Comparando se a prioridade da espaçonave com tamanho menos 1 dividido por 2
    // é menor que a prioridade da nave do tamanho passado
    // O valor de 'i' deve ser maior que 0
    while (i > 0 && heap->naves[(i - 1) / 2]->prioridade < heap->naves[i]->prioridade) {
        trocarEspaconaves(&heap->naves[i], &heap->naves[(i - 1) / 2]); // Trocar a posição prioritária
        i = (i - 1) / 2; // Calcular a metade para o novo valor de 'i', valor pai
    }
}

// FUNÇÃO PARA REMOVER A ESPAÇONAVE COM MAIOR PRIORIDADE DO HEAP
struct Espaconave *removerEspaconave(struct Heap *heap)
{
    // Verifica se o Heap está vazio
    if (heap->tamanho <= 0) return NULL;

    // Se o Heap tiver apenas um elemento
    if (heap->tamanho == 1) {
        heap->tamanho--; // Decresce o tamanho do Heap em menos 1
        return heap->naves[0]; // Retorna a raiz do Heap (único elemento)
    }

    struct Espaconave *raiz = heap->naves[0]; // Armazena a nave da raiz do Heap em uma variável
    heap->naves[0] = heap->naves[heap->tamanho - 1]; // Substitui a nave raiz pela última do Heap
    heap->tamanho--; // Decresce o tamanho do Heap em menos 1
    organizarHeap(heap, 0); // Organiza o Heap das naves a partir do Heap raiz
    imagemEspaconave(); // Exibe imagem de uma nave viajando

    return raiz;
}

// FUNÇÃO PARA LER O ARQUIVO COM AS INFORMAÇÕES INICIAIS DAS ESPACONAVES
struct Heap *arquivoEspaconaves()
{
    int prioridade;
    struct Heap *heap = criarHeap(100);

    printf("-----------------------------------------------------------------------\n\n");
    printf("LENDO O ARQUIVO DA LISTA DE ESPACONAVES...\n\n");

    // Abre o arquivo em modo de leitura
    FILE *arquivo = fopen("espaconaves.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s.\n", "naves.txt");
        printf("-----------------------------------------------------------------------\n\n");
        return NULL;
    } else {
        // Lê os números do arquivo e os imprime na tela
        while (fscanf(arquivo, "%d", &prioridade) != EOF) {
            inserirEspaconave(heap, prioridade, gerarQtdPassageiros(), gerarQtdRecursos());
        }

        // Fecha o arquivo após a leitura
        fclose(arquivo);

        printf("ARQUIVO LIDO COM SUCESSO! Lista de espaconaves adicionada e organizada.\n\n");

        return heap;
    }
}

// FUNÇÃO PARA IMPRIMIR A IMAGEM DE UM FOGUETE
int imagemEspaconave()
{
    struct timespec delay;
    delay.tv_sec = 0;          // 0 segundos
    delay.tv_nsec = 200000000;

    printf("\t      |\n");
    printf("\t     / \\ \n");
    printf("\t    / _ \\ \n");
    printf("\t   | (_) |\n");
    printf("\t   |  _  |\n");
    printf("\t   | (_) |\n");
    printf("\t  /       \\ \n");
    printf("\t |_________|\n");

    for (int i = 0; i < 10; i++) {
        nanosleep(&delay, NULL);
        printf("\t   |  |  |\n");
    }

    nanosleep(&delay, NULL);
    printf("\t   |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t   |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t  (  |  |  )\n");
    nanosleep(&delay, NULL);
    printf("\t  |  |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t  |  |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t (  |  |  |  )\n");
    nanosleep(&delay, NULL);
    printf("\t |  |  |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t |  |  |  |  |\n");
    nanosleep(&delay, NULL);
    printf("\t (  |  |  |  )\n");
    nanosleep(&delay, NULL);
    printf("\t  |__|__|__|\n");
    nanosleep(&delay, NULL);
    printf("\t   |  |  |\n\n");
    nanosleep(&delay, NULL);
    printf("     |  |   |  |  |  |  |   |  \n");
    nanosleep(&delay, NULL);
    printf("   |   |  |  |  |  |   |  |  |\n");
    nanosleep(&delay, NULL);
    printf(" |  |   Viagem espacial    |  |  |\n");
    nanosleep(&delay, NULL);
    printf("   |  |  |   |  |  |  |  |  |\n");
    nanosleep(&delay, NULL);
    printf("    |  |   |  |  |  |  |   |\n");
    nanosleep(&delay, NULL);
    printf("      |  |  |  |  |  |  |   \n");
    nanosleep(&delay, NULL);
    system("pause");
    printf("\n\n");
    return 0;
}
