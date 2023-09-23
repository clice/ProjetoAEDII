#define LISTADEFOGUETES_H_INCLUDED


//Dados
typedef struct{
    char nome[50];
    int chave;
} Nave;

typedef struct {
     Nave *dados;
     int tam,n;
}heap;

//funções

heap* heap_criar(int tam);
void destruir_heap(heap **h);
void adicionar_nave(heap *h,Nave x);
Nave entrar_no_portal(heap *h);
int heap_cheio(heap *h);
int heap_vazia(heap *h);
void sobe_no_heap(heap *h, int pos );
void desce_no_heap(heap *h, int pos);


