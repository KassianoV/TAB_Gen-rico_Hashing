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
    
    getchar();

    printf("\nInforme o nome do aluno: ");
    fgets(al->nome,100,stdin);
    
    if(al->nome[strlen(al->nome)-1]=='\n')
        al->nome[strlen(al->nome)-1]='\0';
    
    printf("\nInforme o email do aluno: ");
    fgets(al->email,100,stdin);

    if(al->email[strlen(al->email)-1]=='\n')
        al->email[strlen(al->email)-1]='\0';
    
    printf("\nInforme a matricula do aluno: ");
    scanf("%d",&al->matricula);

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

aluno *InicializaAluno(){
    aluno *al=(aluno *) malloc(sizeof(aluno));
}

int main(){
    int mat;
    int opcao=0,aux;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    aluno *al=InicializaAluno();
    InicializaArq(nomeArq, al,sizeof(aluno));
    
    while(opcao != 4){
        opcao=menu();
        switch (opcao){
            case 1:
                al=CriaAluno();
                Inserir(nomeArq, al->matricula, al, sizeof(aluno));
                break;
            case 2:
                printf("\nDigite o numero da matricula do aluno: ");
                scanf("%d",&mat);
                if(BuscarObj(nomeArq,mat,al,sizeof(struct aluno))==1){
                    printf("Os dados do aluno sao:\n");
                    printf("\nMatricula: %d\nNome: %s\nEmail: %s\nCR: %.2f\n",al->matricula,al->nome,al->email,al->CR);
                }else
                    printf("Nao ha um aluno com matricula %d no registro",mat);
                break;
            case 3:
                printf("\n");
                leituraCompleta(nomeArq);
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