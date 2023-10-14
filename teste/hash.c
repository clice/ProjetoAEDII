#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "espaconave.h"
#define TAM 20

void iniciaLista(Lista *l){
    l->inicio=Null;
    l->tam=0;


}


void inserirNo(Lista *l, int valor){
    Espaconave *novo =malloc(sizeof(Espaconave));

    if(novo){
        novo->chave=valor;
        novo->proximo = l->inicio;
        l->inicio=novo;

    }
    else{
        printf("\n erro \n")
    }
 }


void iniciaTabela(Lista t[]){
    int i;
    for(i=0;i<TAM,i++){
        iniciaLista(&t[i]);
    }



}


 int bucarlista( Lista *l, int valor){
     No *aux= l->inicio;
     while (aux && aux->chave!= valor){
        aux=aux->proximo;
        }
        if (aux){
            return aux->chave;
        }
     return 0;
     }



void inserir(int t[] , int valor){
    int id =funcaoHash(valor);
    while (t[id] !=0){
        id=funcaoHash(id+1);

    }
    t[id]=valor;
}



int busca(int t[],int chave){
    int id=funcaoHash(chave);
    while(t[id]!=0){
        if(t[id]==chave){
            return t[id];

        }
        else{
            id=funcaoHash(id+1);
        }

    }


}


