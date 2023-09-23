#include <stdio.h>
#include <stdlib.h>
#include "Filadefoguetes.h"



int main(){
    int n,i;
    printf("Digite o tamanho da fila que desejas criar\n");
    scanf("%d",&n);
    heap *heap= heap_criar(n);
    for(i=0;i<n;i++){
        Nave nav;
        printf("digita a prioridade \n ");
        scanf("%d",&nav.chave);
        printf("Digite o nome da nave");
        scanf("%s",&nav.nome);
        adicionar_nave(heap,nav);
    }
    printf("Fila");
    while(!heap_vazia(heap)){
        Nave nav= entrar_no_portal(heap);
        printf("%d, %s \n",nav.chave,nav.nome);

    }
    destruir_heap(heap);



return 0;
}
