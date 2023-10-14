#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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


