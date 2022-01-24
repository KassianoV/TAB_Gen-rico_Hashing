#include <stdio.h>
#include <stdlib.h>
#include "HashingGen.h"
#include <string.h>

typedef struct professor{
    int matricula;
    char nome[100];
    double salario;
}*Professor;

Professor *CriaProfessor(){
    Professor pf=(Professor) malloc(sizeof(struct professor));
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

int menu(){
    int opc;
    printf("\nEscolha uma opcao:\n");
    printf("[1] Adicionar um aluno\n");
    printf("[2] Imprimir informacoes de um Aluno\n");
    printf("[3] Imprimir Tabela Hash\n");
    printf("[4] Encerrar\n");
    scanf("%d",&opc);
    return opc;
}

Professor *InicializaAluno(Professor pf){
    pf=(Professor) malloc(sizeof(Professor));
}

int main(){
    int mat;
    int opcao=0,aux;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    Professor pf=InicializaAluno(pf);
    InicializaArq(nomeArq, pf,sizeof(Professor));
    
    while(opcao != 4){
        opcao=menu();
        switch (opcao){
            case 1:
                pf=CriaProfessor();
                Inserir(nomeArq, 0, pf, sizeof(Professor));
                break;
            case 2:
                printf("\nDigite o numero da matricula do professor: ");
                scanf("%d",&mat);
                if(BuscarObj(nomeArq,mat,pf,sizeof(struct professor))==1){
                    printf("Os dados do professor sao:\n");
                    printf("Matricula: %d\nNome: %s\nEmail: %d",pf->matricula, pf->nome, pf->salario);
                }else
                    printf("Nao ha um aluno com matricula %d no registro",mat);
                break;
            case 3:
                printf("\n");
                leituraCompleta(nomeArq);
                break;
                break;
            case 4:
                printf("Saindo...");
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
    }

    return 0;
}