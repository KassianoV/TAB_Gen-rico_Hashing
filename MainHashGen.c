#include <stdio.h>
#include <stdlib.h>
#include "HashingGen.h"
#include <string.h>

<<<<<<< HEAD
struct aluno {
    int matricula;
    char nome[100];
    char email[100];
    float CR;
};

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

Aluno CriaAluno(){
    Aluno al=(Aluno) malloc(sizeof(struct aluno));
    printf("\nInforme a matricula do aluno: ");
    scanf("%d",&al->matricula);
    getchar();

    printf("\nInforme o nome do aluno: ");
    gets(al->nome);
    
    if(al->nome[strlen(al->nome)-1]=='\n')
        al->nome[strlen(al->nome)-1]='\0';
    
    printf("\nInforme o email do aluno: ");
    gets(al->email);
=======
// falta a main tudo e dar uma revisada na biblioteca tá quase tudo completo já

int main(){
    int mat;
    int opcao;
    Pessoa *p;
>>>>>>> ba9a94f85c0ad6124eb0e34293354e84a608ebe3

    if(al->email[strlen(al->email)-1]=='\n')
        al->email[strlen(al->email)-1]='\0';
    
    printf("\nInforme o CR do aluno: ");
    scanf("%f",&al->CR);

    return al;
}

int main(){
    int mat;
    int opcao=0;
    char nomeArq[13];
    strcpy(nomeArq,"registro.bin");
    //Professor p = (Professor) malloc (sizeof(struct professor));
    
    while(opcao != 4){
<<<<<<< HEAD
        opcao=menu();
        switch (opcao){
            case 1:
                Aluno a=CriaAluno();
                Inserir(nomeArq, 0, a, sizeof(struct aluno));
                break;
            case 2:
                printf("\nDigite o numero da matricula do aluno: ");
                scanf("%d",&mat);
                BuscaAluno(nomeArq,mat);
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
=======
        switch (opcao){
        case 1:


            break;

        case 2:


            break;

        case 3:


            break;

        case 4:

            printf("Saindo...");
            break;
        
        default:
            break;
>>>>>>> ba9a94f85c0ad6124eb0e34293354e84a608ebe3
        }
    }

    return 0;
}