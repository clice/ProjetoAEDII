#include <stdio.h>
#include <stdlib.h>
#include "Filadefoguetes.h"
#define swap(a,b) {Nave tmp=*a; *a=*b ;*b=tmp;}
#define F_esq(i) (2*i+1)
#define F_dir(i) (2*i+2)
#define PAI(i)


heap* heap_criar(int tam){
    heap* h=(heap*)malloc(tam*sizeof(Nave));
    h->dados =(heap*)malloc(tam*sizeof(Nave));
    h->n=0;
    h->tam=tam;

    return (h);
}


void destruir_heap(heap **h){
    free((*h)->dados);
    free(*h);
    *h=NULL ;

}

int heap_vazia(heap *h){
    return (h->n==0);

}

int heap_cheio(heap *h){

    return h->n==h->tam;
}
void adicionar_nave(heap *h, Nave nav){
   h->dados[h->n]=nav;
   h->n++;
   sobe_no_heap(h,h->n-1);

}

Nave entrar_no_portal(heap *h){
    int j,max=0;
    for(j=1; j< h->n;j++){
        if(h->dados[max].chave < h->dados[j].chave){
            max=j;
        }
    }
    swap(&(h->dados[max]),&(h->dados[h->n-1]));
    h->n--;
    return (h->dados[h->n]);
}


void sobe_no_heap(heap *h, int pos ){
    if(pos>0 && h->dados(PAI(pos)).chave< h->dados(pos).chave){
        swap(&h->dados(pos),&h->dados(PAI(pos));
        sobe_no_heap(h,PAI(pos));
    }


}

void desce_no_heap(heap *h, int pos){
    if(F_esq(pos)< h->n){
        int maior_filho=F_esq(pos);
        int a=h->dados[pos].chave;
        int b=h->dados[maior_filho].chave;
        if ((F_dir(pos)< h->n) && h->dados[F_esq(pos)].chave< h->dados[F_dir(pos)].chave){
            maior_filho=F_dir(pos);

        }
        if((a) < (b)){
            swap(&h->dados(pos), &h->dados(maior_filho));
            desce_no_heap(h,maior_filho);
        }

    }

}
