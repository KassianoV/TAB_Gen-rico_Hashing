#include<stdio.h>
#include<stdlib.h>
#include"HashingGen.h"
#include<string.h>
#define N 11



struct professor{
    int matricula;
    char nome[100];
    double salario;
};

struct pessoa{ 
    int tipo;   // Tipo 1 aluno e 2 prof
    int chave;      
    void *item;
};

void InicializaArq(char * nomeArq, void *obj, int sizeObj){
    FILE *arq = fopen(nomeArq,"wb");
    Pessoa a;

    a.item = (void*) malloc(sizeObj);
    memcpy(a.item, obj, sizeObj);

    int i;
    if(a.tipo == 1){
        for(i=0; i<N; i++)
            fwrite(&a, sizeof(Pessoa),1,arq);
        fclose(arq);
    }    
    else if(a.tipo == 2){
        for(i=0; i<N; i++)
            fwrite(&a, sizeof(Pessoa),2,arq);
        fclose(arq);
    }
}
// int hash1 (Pessoa item, int size){
//     if(item.tipo == 1){
//         Aluno al=(Aluno) item.item;
//         return al->matricula%size;
//     }else if(item.tipo==2){
//         Professor prof=(Professor) item.item;
//         return prof->matricula%size;
//     }
// }

// int hash2(Pessoa p, int size){
//     int key;
//     if(p.tipo==1){
//         Aluno al=(Aluno) p.item;
//         key=size-2-(al->matricula%(size-2));
//     }else if(p.tipo==2){
//         Professor prof=(Professor) p.item;
//         key=size-2-(prof->matricula%(size-2));
//     }
//     return key;
// }

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj){
    int pos = AcharPosicao(nomeArq, key, sizeObj);
    Pessoa aux;

    FILE *arq = fopen(nomeArq, "r+b");

    aux.item = (void*) malloc(sizeObj);
    memcpy(aux.item, objeto, sizeObj);

    aux.chave = key;
    fseek(arq, pos*sizeof(aux), SEEK_SET);

    if(aux.tipo == 1)
        fwrite(&aux, sizeof(aux),1,arq);
    else if(aux.tipo == 2)
        fwrite(&aux, sizeof(aux), 2,arq);
    fclose(arq);
}

int AcharPosicao(char *nomeArq, int key,int sizeObj){
   Pessoa aux;
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
    Pessoa aux;
    FILE *arq = fopen (nomeArq, "rb");
    int i;

    for(i=0; i<N; i++){
        fread(&aux, sizeof(aux), 1, arq);

        if(aux.chave == key){
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
    Pessoa aux;
    FILE *arq = fopen(nomeArq, "rb");
    int i;

    for (i=0; i<N; i++){
        fread(&aux, sizeof(aux), 1, arq);
        if(aux.tipo != 1)
            printf("%i\n", aux.chave);
        else    
            printf("Disponivel - \n");
    }
    printf("\n");
    fclose(arq);
}

// void Printa(Pessoa *p, int size){
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
>>>>>>> ba9a94f85c0ad6124eb0e34293354e84a608ebe3



