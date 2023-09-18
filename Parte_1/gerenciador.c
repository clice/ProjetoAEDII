#include <stdio.h>
#include <stdlib.h>


*Fila fila_criar(int tam){
    Fila* f=(Fila*)malloc(tam*sizeof(Nave));
    f->dados =(Nave*)malloc(tam*sizeof(Nave));
    f->n=0;
    p->tam=tam;

    return (f);
}


void destruir_fila(Fila **f){
    free((*f)->dados0);
    free(*f)
    *f=NULL ;

}

int Fila_vazia(Fila *f){
    return (f->n==0);

}

int Fila_cheia(Fila *f){

    return f->n==f->tam;
}
void adicionar_nave(Fila *f, Nave nav){
    if(!Fila_cheia(f)){
        f->dados[f->n]= nav;
    }
     p->n++;
}

Nave entrar_no_portal(Fila *f){
    int j,max=0;
    for(j=1; j< p->n;j++){
        if(p->dados[max].chave < f->dados[j].chave){
            max=j;
        }
    swap(&(f->dados[max]),&(f-.dados[p->n-1]));
    f->n--;
    }
    return (f->dados[p->n]);
}
