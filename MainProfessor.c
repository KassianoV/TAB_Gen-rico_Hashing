#include <stdio.h>
#include <stdlib.h>
#include "HashingGen.h"
#include <string.h>

typedef struct professor{
    int matricula;
    char nome[100];
    double salario;
}*Professor;

Professor CriaProfessor(){
    Professor pf=(Aluno) malloc(sizeof(struct professor));
    printf("\nInforme a matricula do professor: ");
    scanf("%d",&pf->matricula);
    getchar();

    printf("\nInforme o nome do professor: ");
    gets(pf->nome);
    
    if(pf->nome[strlen(pf->nome)-1]=='\n')
        pf->nome[strlen(pf->nome)-1]='\0';
    
    printf("\nInforme o salario do professor: ");
    scanf("%d",pf->salario);
    
    return pf;
}

int main(){
    int mat;
    int opcao=0;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    Aluno pf;
    //Professor p = (Professor) malloc (sizeof(struct professor));
    
    while(opcao != 4){
        opcao=menu();
        switch (opcao){
            case 1:
                pf=CriaAluno();
                Inserir(nomeArq, 0, pf, sizeof(Aluno));
                break;
            case 2:
                printf("\nDigite o numero da matricula do aluno: ");
                scanf("%d",&mat);
                pf=(Aluno) BuscaElemento(nomeArq,mat);
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