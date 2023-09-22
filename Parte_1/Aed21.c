#include <stdio.h>
#include <stdlib.h>
#include "Filadefoguetes.h"




int main(){
   int n, i;
   printf("Digite o tamanho da fila \n");
   scanf("%d", &n);
   Fila* fila= fila_criar(n);
   for (i=0; i<n; i++){
        Nave nav;
        printf("Digite a prioridade da nave \n");
        scanf("%d", &nav.chave);
        printf("Digite o nome da nave \n");
        scanf("%s", nav.nome);

        adicionar_nave(fila, nav);

   }
   while(!Fila_vazia(fila)){
        Nave nav= entrar_no_portal(fila);
        printf("%d %s \n",nav.chave,nav.nome);
   }
   destruir_fila(&fila);





return 0;
}
