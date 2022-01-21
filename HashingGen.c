#include<stdio.h>
#include<stdlib.h>
#include"HashingGen.h"
#include<string.h>
#define N 11

typedef struct elemento{
    int tipo,key;
    void *item;
}Elemento;

//Aluno 
struct aluno {
    int matricula;
    char nome[100];
    char email[100];
    float CR;
};

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

    if(al->email[strlen(al->email)-1]=='\n')
        al->email[strlen(al->email)-1]='\0';
    
    printf("\nInforme o CR do aluno: ");
    scanf("%f",&al->CR);

    return al;
}

// Professor 
struct professor{
    int matricula;
    char nome[100];
    double salario;
};

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

struct Elemento{ 
    int tipo;   // Tipo 1 aluno e 2 prof
    int key;      
    void *item;
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

// Ok
void InicializaArq(char * nomeArq, void *obj, int sizeObj){
    FILE *arq = fopen(nomeArq,"wb");
    Elemento a;

    a.item = (void*) malloc(sizeObj);
    memcpy(a.item, obj, sizeObj);
    a.tipo=-1;
    a.key=-1;

    for(int i=0; i<N; i++)
        fwrite(&a, sizeof(Elemento),1,arq);

    fclose(arq);
}

int hashArq(char *nomeArq, int mat){
    
}
int hash1 (Elemento item, int size){
    if(item.tipo == 1){
        Aluno al=(Aluno) item.item;
        return al->matricula%size;
    }else if(item.tipo==2){
        Professor prof=(Professor) item.item;
        return prof->matricula%size;
    }
}

int hash2(Elemento p, int size){
    int key;
    if(p.tipo==1){
        Aluno al=(Aluno) p.item;
        key=size-2-(al->matricula%(size-2));
    }else if(p.tipo==2){
        Professor prof=(Professor) p.item;
        key=size-2-(prof->matricula%(size-2));
    }
    return key;
}

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj){
    int pos = AcharPosicao(nomeArq, key, sizeObj);
    Elemento aux;

    FILE *arq = fopen(nomeArq, "r+b");

    aux.item = (void*) malloc(sizeObj);
    memcpy(aux.item, objeto, sizeObj);

    aux.key = key;
    fseek(arq, pos*sizeof(aux), SEEK_SET);

    if(aux.tipo == 1)
        fwrite(&aux, sizeof(aux),1,arq);
    else if(aux.tipo == 2)
        fwrite(&aux, sizeof(aux), 2,arq);
    fclose(arq);
}

int AcharPosicao(char *nomeArq, int key,int sizeObj){
    Elemento aux;
    aux.item = (void*) malloc(sizeObj);

    int pos = hash1(aux ,N);
    int deslocamento =  hash2(aux, N);

    FILE *arq = fopen(nomeArq, "rb");
    fseek(arq, pos * sizeof(aux), SEEK_SET);
    fread(&aux, sizeof(aux), 1,arq);

    while (aux.tipo == 0){
        pos = (pos + deslocamento) % N;
        fseek(arq, pos *sizeof(aux), SEEK_SET);
        fread(&aux, sizeof(aux),1, arq);
    }
    fclose(arq);
    return pos;
}

int BuscarObj(char * nomeArq, int key, void *resp, int sizeObj){
    Elemento aux;
    FILE *arq = fopen (nomeArq, "rb");
    int i;

    for(i=0; i<N; i++){
        fread(&aux, sizeof(aux), 1, arq);

        if(aux.key == key){
            resp = (void*) malloc(sizeObj);
            memcpy(resp, aux.item, sizeObj);
            fclose(arq);
            return 1;
        }
    }
    return 0;
    fclose(arq);
}

void leituraCompleta(char * nomeArq){
    Elemento aux;
    FILE *arq = fopen(nomeArq, "rb");
    int i;

    for (i=0; i<N; i++){
        fread(&aux, sizeof(aux), 1, arq);
        if(aux.tipo != 1)
            printf("%i\n", aux.key);
        else    
            printf("Disponivel - \n");
    }
    printf("\n");
    fclose(arq);
}

// void Printa(Elemento *p, int size){
//     for(int i=0;i<size;i++){
//         if(p[i].tipo==1){
//             Aluno al=(Aluno) p[i].item;
//             printf("\nAluno\n");
//             printf("%d\n",al->matricula);
//             printf("%s\n",al->nome);
//             printf("%s\n",al->email);
//             printf("%.2f\n",al->CR);
//         }else if(p[i].tipo==2){
//             Professor prof=(Professor) p[i].item;//esqueci do = kkkkkkkkkkkkkkkk
//             printf("\nProfessor\n");
//             printf("%d\n",prof->matricula);
//             printf("%s\n",prof->nome);
//             printf("%.2lf\n",prof->salario);
//         }
//     }
// }