#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

#include "espaconave.h"

void inicializarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, char recursos[4])
{
    No *novo = malloc(sizeof(No));

    if (novo) {
        for (int i = 0; i < 4; i++) {
            novo->sequencia[i] = recursos[i];
        }

        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else printf("\n\tErro ao alocar memoria!\n");
}

int buscar_na_lista(Lista *l, int valor)
{
    No *aux = l->inicio;

    while (aux && aux->chave != valor) aux = aux->proximo;

    if (aux) return aux->chave;
    return 0;
}

void inicializarTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++) inicializarLista(&t[i]);
}

int funcaoHash(int chave)
{
    switch (chave) {
    case 111:
        return 0;
    case 1011:
        return 1;
    case 10011:
        return 2;
    case 100011:
        return 3;
    case 1101:
        return 4;
    case 10101:
        return 5;
    case 100101:
        return 6;
    case 11001:
        return 7;
    case 101001:
        return 8;
    case 110001:
        return 9;
    case 1110:
        return 10;
    case 10110:
        return 11;
    case 100110:
        return 12;
    case 11010:
        return 13;
    case 101010:
        return 14;
    case 110010:
        return 15;
    case 11100:
        return 16;
    case 101100:
        return 17;
    case 110100:
        return 18;
    case 111000 :
        return 19;
    }
}

int verificaRepeticao (Lista *l, char recurso[4])
{
    No *aux = l->inicio;

    while(aux && (strcmp(aux->sequencia, recurso) != 0)) aux = aux->proximo;

    if (aux) return 1;

    return 0;
}

// Funcao para calcular a soma dos valores associados �s letras na sequ�ncia
//calcularSomaSequencia
int calcularID(char sequencia[4])
{
    int valores[6] = {1, 10, 100, 1000, 10000, 100000};
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        switch (sequencia[i]) {
            case 'A':
                soma += valores[0];
                break;
            case 'B':
                soma += valores[1];
                break;
            case 'C':
                soma += valores[2];
                break;
            case 'D':
                soma += valores[3];
                break;
            case 'E':
                soma += valores[4];
                break;
            case 'F':
                soma += valores[5];
                break;
        }
    }

    return soma;
}

void inserir(Lista t[],char recurso[4])
{
    int id = funcaoHash(calcularID(recurso));
    inserir_na_lista(&t[id], recurso);
}

int busca(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

char gerarLetraAleatoria(char letrasUsadas[], int tamanho)
{
    char letrasRestantes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int letrasRestantesCount = 6 - tamanho;
    int indiceAleatorio = rand() % letrasRestantesCount;

    for (int i = 0; i < tamanho; i++) {
        if (letrasUsadas[i] == letrasRestantes[indiceAleatorio]) {
            // Se a letra j� foi usada, ajusta o �ndice aleat�rio
            indiceAleatorio = (indiceAleatorio + 1) % letrasRestantesCount;
            i = -1; // Volta ao in�cio do loop para verificar novamente
        }
    }

    return letrasRestantes[indiceAleatorio];
}

// Funcao para gerar uma sequ�ncia de tr�s letras aleat�rias sem repeti��es
void gerarSequenciaAleatoria(char sequencia[4])
{
    char letrasUsadas[3] = {0}; // Inicializa com zeros

    for (int i = 0; i < 3; i++) {
        sequencia[i] = gerarLetraAleatoria(letrasUsadas, i);
        letrasUsadas[i] = sequencia[i];
    }

    sequencia[3] = '\0'; // Adiciona um caractere nulo para criar uma string v�lida
}

// char* generateRandomLetters()
// {
//     char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
//     char* result = (char*)malloc(4); // 4 characters (3 letters + '\0')

//     if (result != NULL) {
//         srand(time(NULL)); // Inicializa a semente do gerador de n�meros aleat�rios com o tempo atual

//         for (int i = 0; i < 3; i++) {
//             int randomIndex = rand() % 6; // Gera um �ndice aleat�rio de 0 a 5
//             result[i] = letters[randomIndex];

//             // Remove a letra escolhida para que ela n�o seja escolhida novamente
//             for (int j = randomIndex; j < 5; j++) {
//                 letters[j] = letters[j + 1];
//             }
//         }

//         result[3] = '\0'; // Adiciona o caractere nulo ao final da string
//     }

//     return result;
// }

void imprimir(Lista t[])
{
    for (int i = 0; i < TAM; i++) {
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

void imprimir_lista(Lista *l)
{
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);

    while (aux) {
        printf("Recursos da nave: %s\n", aux->sequencia);
        aux = aux->proximo;
    }
}

int verificarTamanho(Lista t[])
{
    int tamanho = 0;

    for(int i = 0; i < TAM; i++) {
        tamanho = Verifica_Tam(&t[i]);
        if (tamanho == 6) break;
    }

    return(tamanho);
}

int Verifica_Tam(Lista *l)
{
    No *aux = l->inicio;
    while(aux){
        if(l->tam==6){
            return 6;
            break;
        }
    printf("???");
    aux=aux->proximo;

    }

    return 0;
}

// FUNÇÃO PARA LER O ARQUIVO COM AS INFORMAÇÕES DOS RECURSOS
struct Lista *arquivoRecursos(Lista t[])
{
    // struct Heap *heap = criarHeap(100);
    char recurso[4]; // Tamanho máximo de uma linha

    printf("-------------------------------------------------------------------------------------------\n\n");
    printf("LENDO O ARQUIVO DA LISTA DE RECURSOS...\n\n");

    // Abre o arquivo em modo de leitura
    FILE *arquivo = fopen("recursos.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s.\n", "recursos.txt");
        printf("-------------------------------------------------------------------------------------------\n\n");
        return NULL;
    } else {
        // Lê os números do arquivo e os imprime na tela
        while (fgets(recurso, sizeof(recurso), arquivo) != NULL) {
            // inserirEspaconave(heap, prioridade, gerarQtdPassageiros(), gerarQtdRecursos());
            printf("%s", recurso);
            //int id = funcaoHash(calcularID(recurso));

            //if (verificaRepeticao(&tabela[id], recurso) == 0) {
                //inserir(tabela, recurso);
            //}
        }

        // Fecha o arquivo após a leitura
        fclose(arquivo);

        printf("\n\nARQUIVO LIDO COM SUCESSO! Lista de recursos adicionada e organizada.\n\n");

        // return heap;
    }
}
