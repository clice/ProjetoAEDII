// FUNÇÃO PARA INSEIR UMA NAVE NO HEAP
void inserirNave(struct Heap *heap, )
{
    if (heap->tamanho >= heap->capacidade) {
        printf("O Heap está cheio. Não é possível inserir mais naves.\n");
        return;
    }

    int indice = heap->tamanho; // Obtém o índice onde a nova nave será inserida
    heap->tamanho++; // Aumenta o tamanho do Heap

    // Define a prioridade e o nome da nova nave no índice apropriado
    heap->naves[indice].prioridade = prioridade;
    strcpy(heap->naves[indice].nome, nome);

    // Corrige o Heap para manter a propriedade de Heap de Min
    while (indice > 0 && heap->naves[(indice - 1) / 2].prioridade > heap->naves[indice].prioridade) {
        trocar(&heap->naves[(indice - 1) / 2], &heap->naves[indice]); // Troca a nave com seu pai se a propriedade for violada
        indice = (indice - 1) / 2; // Move para o pai
    }
}

// Função para extrair a nave com a menor prioridade (topo do Heap)
struct Nave pop(struct Heap *heap) {
    if (heap->tamanho <= 0) {
        printf("O Heap está vazio. Não é possível extrair naves.\n");
        exit(1);
    }

    struct Nave minNave = heap->naves[0];
    heap->tamanho--;

    heap->naves[0] = heap->naves[heap->tamanho];

    // Corrige o Heap para manter a propriedade de Heap de Min
    int indice = 0;
    while (1) {
        int filhoEsquerda = 2 * indice + 1;
        int filhoDireita = 2 * indice + 2;
        int menor = indice;

        if (filhoEsquerda < heap->tamanho && heap->naves[filhoEsquerda].prioridade < heap->naves[menor].prioridade) {
            menor = filhoEsquerda;
        }

        if (filhoDireita < heap->tamanho && heap->naves[filhoDireita].prioridade < heap->naves[menor].prioridade) {
            menor = filhoDireita;
        }

        if (menor == indice) {
            break;
        }

        trocar(&heap->naves[indice], &heap->naves[menor]);
        indice = menor;
    }

    return minNave;
}

// Função para liberar a memória alocada para o Heap
void liberarHeap(struct Heap *heap) {
    free(heap->naves);
    free(heap);
}

int main() {
    struct Heap *heap = criarHeap(100);

    // Adicionando naves ao Heap
    push(heap, 3, "Nave 3");
    push(heap, 1, "Nave 1");
    push(heap, 2, "Nave 2");

    // Extraindo as naves do Heap na ordem de prioridade
    while (heap->tamanho > 0) {
        struct Nave minNave = pop(heap);
        printf("Prioridade: %d, Nome: %s\n", minNave.prioridade, minNave.nome);
    }

    // Liberando a memória alocada para o Heap
    liberarHeap(heap);

    return 0;
}

// int main() {
//     int numero;
//     FILE *arquivo;
//     char nomeArquivo[] = "numeros.txt"; // Substitua pelo nome do seu arquivo
//     struct Heap *heap = criarHeap(10);

//     // Abre o arquivo em modo de leitura
//     arquivo = fopen(nomeArquivo, "r");

//     // Verifica se o arquivo foi aberto com sucesso
//     if (arquivo == NULL) {
//         printf("Não foi possível abrir o arquivo %s.\n", nomeArquivo);
//         return 1;
//     }

//     // Lê os números do arquivo e os imprime na tela
//     while (fscanf(arquivo, "%d", &numero) != EOF) {
//         printf("Inserir: %d\n", numero);
//         inserir(heap, numero);
//         imprimirHeap(heap);
//     }

//     // Fecha o arquivo após a leitura
//     fclose(arquivo);

//     return 0;
// }

// int main() {
//     struct MaxHeap *heap = criarHeap(10);

//     inserir(heap, 10);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 20);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 15);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 40);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 50);
//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);
//     inserir(heap, 30);

//     printf("Max Heap after insertion:\n");
//     imprimirHeap(heap);

//     return 0;
// }
