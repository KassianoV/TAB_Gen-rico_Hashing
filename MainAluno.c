#include <stdio.h>
#include <stdlib.h>
#include "HashingGen.h"
#include <string.h>

// falta a main tudo e dar uma revisada na biblioteca tá quase tudo completo já
// int main(){
//     int mat;
//     int opcao;
//     Pessoa *p;

int main(){
    int mat;
    int opcao=0;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    Aluno al;
    //Professor p = (Professor) malloc (sizeof(struct professor));
    
    while(opcao != 4){
        opcao=menu();
        switch (opcao){
            case 1:
                al=CriaAluno();
                Inserir(nomeArq, 0, al, sizeof(Aluno));
                break;
            case 2:
                printf("\nDigite o numero da matricula do aluno: ");
                scanf("%d",&mat);
                al=(Aluno) BuscaElemento(nomeArq,mat);
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
    }

    return 0;
}