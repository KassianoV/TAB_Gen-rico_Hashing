#include <stdio.h>
#include <stdlib.h>
#include "HashingGen.h"
#include <string.h>
typedef struct aluno {
    int matricula;
    char nome[100];
    char email[100];
    float CR;
}aluno;

aluno *CriaAluno(){
    aluno *al=(aluno *) malloc(sizeof(struct aluno));
    printf("\nInforme a matricula do aluno: ");
    scanf("%d",&al->matricula);
    getchar();

    printf("\nInforme o nome do aluno: ");
    gets(al->nome);
    
    if(al->nome[strlen(al->nome)-1]=='\n')
        al->nome[strlen(al->nome)-1]='\0';
    
    printf("\nInforme o email do aluno: ");
    gets(al->email);

    if(al->email[strlen(al->email)-1]=='\n')
        al->email[strlen(al->email)-1]='\0';
    
    printf("\nInforme o CR do aluno: ");
    scanf("%f",&al->CR);

    return al;
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

int main(){
    int mat;
    int opcao=0;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    aluno *al;
    //Professor p = (Professor) malloc (sizeof(struct professor));
    
    while(opcao != 4){
        opcao=menu();
        switch (opcao){
            case 1:
                al=CriaAluno();
                Inserir(nomeArq, 0, al, sizeof(aluno));
                break;
            case 2:
                printf("\nDigite o numero da matricula do aluno: ");
                scanf("%d",&mat);
                al=(aluno *) BuscaElemento(nomeArq,mat);
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