<<<<<<< HEAD
//#ifndef LISTADEFOGUETES_H_INCLUDED
//#define LISTADEFOGUETES_H_INCLUDED
//
////Dados
//struct Nave{
//    char nome[50];
//    int chave;
//};
//
//struct Fila{
//    Nave *dados;
//    int tam,n;
//};
//
////funï¿½ï¿½es
//
//*Fila fila_criar(int tam);
//void destruir_fila(Fila **f);
//void adicionar_nave(Fila *f,Nave x);
//Nave entrar_no_portal(Fila *f);
//
//int Fila_cheia(Fila *f);
//int Fila_vazia(Fila *f);
//
=======
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


>>>>>>> 5e58219ebf4b90778ed2ccdbbc0b5aeef4336d4a
