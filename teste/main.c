#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma letra aleatória entre A e F, sem repetições
char gerarLetraAleatoria(char letrasUsadas[], int tamanho) {
    char letrasRestantes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int letrasRestantesCount = 6 - tamanho;

    int indiceAleatorio = rand() % letrasRestantesCount;

    for (int i = 0; i < tamanho; i++) {
        if (letrasUsadas[i] == letrasRestantes[indiceAleatorio]) {
            // Se a letra já foi usada, ajusta o índice aleatório
            indiceAleatorio = (indiceAleatorio + 1) % letrasRestantesCount;
            i = -1; // Volta ao início do loop para verificar novamente
        }
    }

    return letrasRestantes[indiceAleatorio];
}

// Função para calcular a soma dos valores associados às letras na sequência
int calcularSomaSequencia(char sequencia[4]) {
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
// Função para gerar uma sequência de três letras aleatórias sem repetições
void gerarSequenciaAleatoria(char sequencia[4]) {
    char letrasUsadas[3] = {0}; // Inicializa com zeros
    for (int i = 0; i < 3; i++) {
        sequencia[i] = gerarLetraAleatoria(letrasUsadas, i);
        letrasUsadas[i] = sequencia[i];
    }
    sequencia[3] = '\0'; // Adiciona um caractere nulo para criar uma string válida
}

int main() {
    // Inicializa a semente do gerador de números aleatórios com base no tempo atual
    srand(time(NULL));
for(int i=0;i<10;i++){
    char sequencia[4];
    gerarSequenciaAleatoria(sequencia);

    int soma = calcularSomaSequencia(sequencia);

    printf("Sequencia aleatoria de letras: %s\n", sequencia);
    printf("Soma dos valores associados: %d\n", soma);



}

    return 0;
}


