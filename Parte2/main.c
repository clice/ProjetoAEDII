#include <stdio.h>
#include <stdlib.h>
#include "espaconave.h"
#include <time.h>
#include <unistd.h>


int main(){
    int opcao=20, valor, retorno, i,teste;
    Lista tabela[20];
    int soma,id;
    printf("\nSeja Bem Vindo ao Acompanhamento das Naves 5000 Da Big D.O.G cooorp\n");
    printf("\nSo sera possivel a expansão se houver 6 naves com o mesmo recurso so que em combinações diferentes");

    inicializarTabela(tabela);

    while(opcao!=0){
        imprimir(tabela);
        printf("\n\t0 - Sair\n\t1 - Atualizar a lista\n\t2 - Verificar se e possivel fazer a Expansao da entrada  \n");
        scanf("%d", &opcao);
        if(opcao==1) {
            for(i=0;i<10;i++){
                char recurso[4];
                gerarSequenciaAleatoria(recurso);
                int id = funcaoHash(calcularID(recurso));
                if(verificaRepeticao(&tabela[id],recurso)==0){
                    inserir(tabela,recurso);
                }
            }
        }
        else if (opcao==2){
            teste=verificarTamanho(tabela);

            if(teste==6){
                printf("\n Deseja estocar na Abertura?[Y/N] \n");
            }
            else if(teste==0){
                printf("\n Nao e estocar expandir a Abertura \n");
            }


        }



}
 return 0;
}
