#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lista.h"
#include "hash_table.h"

// FUNÇÃO PARA DEFINE A FUNÇÃO HASH PARA ADICIONAR INFO NA HASH TABLE
int funcaoHash(int chave)
{
    switch (chave) {
        case 111:
            return 0;
            break;

        case 1011:
            return 1;
            break;

        case 10011:
            return 2;
            break;

        case 100011:
            return 3;
            break;

        case 1101:
            return 4;
            break;

        case 10101:
            return 5;
            break;

        case 100101:
            return 6;
            break;

        case 11001:
            return 7;
            break;

        case 101001:
            return 8;
            break;

        case 110001:
            return 9;
            break;

        case 1110:
            return 10;
            break;

        case 10110:
            return 11;
            break;

        case 100110:
            return 12;
            break;

        case 11010:
            return 13;
            break;

        case 101010:
            return 14;
            break;

        case 110010:
            return 15;
            break;

        case 11100:
            return 16;
            break;

        case 101100:
            return 17;
            break;

        case 110100:
            return 18;
            break;

        case 111000 :
            return 19;
            break;
    }

    return -1;
}

// FUNÇÃO PARA CALCULAR A SOMA DOS CALORES ASSOCIADOS AS LETRAS NA SEQUÊNCIA
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

// FUNÇÃO PARA INICIALIZAR A HASH TABLE
void inicializarHashTable(Lista t[])
{
    for (int i = 0; i < 20; i++) inicializarLista(&t[i]);
}

// FUNÇÃO PARA INSERIR INFORMAÇÕES NA HASH TABLE
void inserirNaHashTable(Lista t[], char recurso[4])
{
    int id = funcaoHash(calcularID(recurso));
    inserirNaLista(&t[id], recurso);
}

// FUNÇÃO PARA BUSCAR AS INFORMAÇÕES DA HASH TABLE
int buscarNaHashTable(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    return buscarNaLista(&t[id], chave);
}

// FUNÇÃO PARA VERIFICAR O TAMANHO DO HASH TABLE
int verificarTamanhoHashTable(Lista t[])
{
    int tamanho = 0;

    for (int i = 0; i < 20; i++) {
        tamanho = verificarTamanhoLista(&t[i]);
        if (tamanho == 6) break; // Quando tiver encontrado um caso com 6 sai do laço
    }

    return tamanho;
}

// FUNÇÃO PARA IMPRIMIR A HASH TABLE
void imprimirHashTable(Lista t[])
{
    for (int i = 0; i < 20; i++) {
        printf("%2d = ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

// FUNÇÃO PARA LIMPAR A HASH TABLE
void limparHashTable(Lista t[]) {
    int i;

    for(i = 0; i < 20; i++){
       limparLista(&t[i]);
    }

    inicializarHashTable(t);
}

// FUNÇÃO PARA GERAR LETRA ALEATÓRIA PARA GERAR A SEQUÊNCIA
char gerarLetraAleatoria(char letrasUsadas[], int tamanho)
{
    char letrasRestantes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int letrasRestantesCount = 6 - tamanho; // Saber quantas letras faltam
    int indiceAleatorio = rand() % letrasRestantesCount; // Gerar número aleatório

    for (int i = 0; i < tamanho; i++) {
        if (letrasUsadas[i] == letrasRestantes[indiceAleatorio]) {
            // Se a letra já foi usada, ajusta o índice aleatório
            indiceAleatorio = (indiceAleatorio + 1) % letrasRestantesCount;
            i = -1; // Volta ao início do loop para verificar novamente
        }
    }

    return letrasRestantes[indiceAleatorio];
}

// FUNÇÃO PARA GERAR UMA SEQUENCIA DE TRÊS LETRAS ALEATÓRIAS SEM REPETIÇÕES
void gerarSequenciaAleatoria(char sequencia[4])
{
    char letrasUsadas[3] = {0}; // Inicializa com zeros

    for (int i = 0; i < 3; i++) {
        // Chama a função para gerar as letras dos 3 recursos
        sequencia[i] = gerarLetraAleatoria(letrasUsadas, i);
        letrasUsadas[i] = sequencia[i];
    }

    sequencia[3] = '\0'; // Adiciona um caractere nulo para criar uma string válida
}

// FUNÇÃO PARA VERIFICAR SE É POSSÍVEL ABRIR A PASSAGEM
void verificarExpansaoPassagem(Lista t[])
{
    int teste;
    char escolha;

    teste = verificarTamanhoHashTable(t);

    // Se as 6 possibilidades de combinações de recursos forem encontradas
    if (teste == 6) {
        printf("---------------------------------------------------------\n\n");
        printf("\n Finalmente foram encontrados os recursos necessarios!!!! \n");
        printf("\n Desejas expandir a abertura para salvar a galaxia? [Y/N]: ");
        scanf("%c", &escolha);
        escolha = getchar();

        // Realizar a limpeza da tabela
        if (escolha == 'Y'){
            printf("\n---------------------------------------------------------\n\n");
            limparHashTable(t);
        }
        // Imprimir caso o usuário não queira limpar, mas será limpa do mesmo jeito
        else{
            imprimirTristeza();
            sleep(5);
            limparHashTable(t);
        }
    }
    // Caso ainda não seja possível abrir a passagem
    else if (teste == 0){
        printf("\n---------------------------------------------------------\n\n");
        printf("\n AINDA NAO E POSSIVEL EXPANDIR \n");
        printf("\n---------------------------------------------------------\n\n");
        sleep(5);
    }
}

// FUNÇÃO PARA LEITURA DE ARQUIVO COM RECURSOS DEFINIDOS
void arquivoRecursos(Lista t[])
{
    int id;
    char **linhas = NULL;
    size_t numLinhas = 0;

    printf("\nLendo o arquivo da lista de recursos...\n\n");

    // Buffer para armazenar a linha lida
    char linha[5]; // Defina o tamanho apropriado para o seu caso

    // Abre o arquivo em modo de leitura
    FILE *arquivo = fopen("recursos.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s.\n", "recursos.txt");
        printf("---------------------------------------------------------\n\n");
    } else {
        // Loop para ler e armazenar cada linha do arquivo
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            // Remove o caracter de nova linha '\n'
            // size_t é um tipo de dado mesmo que 'int' não sinalizado
            // usado para armazenar o retorno de uma operação sizeof
            size_t len = strlen(linha);
            if (len > 0 && linha[len - 1] == '\n') {
                linha[len - 1] = '\0';
            }

            // Aloca espaço para a linha lida e copia-a para o vetor
            char *novaLinha = strdup(linha); // Requer #include <string.h>
            linhas = (char **)realloc(linhas, (numLinhas + 1) * sizeof(char *));
            linhas[numLinhas] = novaLinha;

            numLinhas++;
        }

        // Fecha o arquivo após a leitura
        fclose(arquivo);

        printf("\nArquivo lido com sucesso! Lista de recursos adicionada.\n\n");
        printf("---------------------------------------------------------\n\n");
    }

    // Exibe os recursos armazenadas
    for (size_t i = 0; i < numLinhas; i++) {
        id = funcaoHash(calcularID(linhas[i]));

        if (verificarRepeticao(&t[id], linhas[i]) == 0) {
            inserirNaHashTable(t, linhas[i]);
        }

        free(linhas[i]); // Libera a memória alocada para cada linha
    }

    imprimirHashTable(t);

    verificarExpansaoPassagem(t);
}


// FUNÇÃO PARA IMPRIMIR TRISTEZA
void imprimirTristeza()
{
    printf("\n---------------------------------------------------------\n\n");
    printf("  .-.-.  \n");
    printf(" / 0 0 \\  Voce so tinha uma funcao, apertar o Y!\n");
    printf("|   l   | Por sua culpa vamos morrer de fome!\n");
    printf(" \\ --  /  PARABENS!\n");
    printf("  '---'  \n\n");
    printf("---------------------------------------------------------\n\n");
}
