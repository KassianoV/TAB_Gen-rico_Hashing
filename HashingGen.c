#include<stdio.h>
#include<stdlib.h>
#include"HashingGen.h"
#include<string.h>
#define N 11

typedef struct elemento{ 
    int tipo;   // Tipo 1 aluno e 2 prof
    int key;      
    void *item;
}*Elemento;

// Ok
void InicializaArq(char *nomeArq, void *obj, int sizeObj){
    FILE *arq = fopen(nomeArq,"wb");
    Elemento a=(Elemento) malloc(sizeof(struct elemento));

    //a->item = (void*) malloc(sizeObj);
    //memcpy(a->item, obj, sizeObj);
    a->item=obj;
    a->tipo=-1;
    a->key=-1;

    for(int i=0; i<N; i++)
        fwrite(&a, sizeof(struct elemento),1,arq);

    fclose(arq);
}

int hashArq(char *nomeArq, int mat){
    
}
int hash1 (Elemento item, int size){
    return item->key%size;
}

int hash2(Elemento p, int size){
    int key;
    key=size-2-(p->key%(size-2));
    return key;
}

int AcharPosicao(char *nomeArq, int key,int sizeObj){
    Elemento aux;
    printf("a\n");
    //aux->item = (void*) malloc(sizeObj);
    printf("a\n");
    int pos = hash1(aux ,N);
    int deslocamento =  hash2(aux, N);
    printf("a %d\n",pos);
    FILE *arq = fopen(nomeArq, "rb");
    printf("a\n");
    fseek(arq, pos * sizeof(struct elemento), SEEK_SET);
    printf("a\n");
    fread(&aux, sizeof(struct elemento), 1,arq);
    printf("a\n");
    while (aux->key != -1){
        pos = (pos + deslocamento) % N;
        fseek(arq, pos *sizeof(struct elemento), SEEK_SET);
        fread(&aux, sizeof(struct elemento),1, arq);
    }
    fclose(arq);
    return pos;
}

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj){
    int pos = AcharPosicao(nomeArq, key, sizeObj);
    printf("\n%d\n",pos);
    Elemento aux=(Elemento) malloc(sizeof(struct elemento));

    FILE *arq = fopen(nomeArq, "r+b");

    aux->item = (void*) malloc(sizeObj);
    memcpy(aux->item, objeto, sizeObj);

    aux->key = key;
    fseek(arq, pos*sizeof(struct elemento), SEEK_SET);

    fwrite(&aux, sizeof(struct elemento),1,arq);
    fclose(arq);
}



int BuscarObj(char * nomeArq, int key, void *resp, int sizeObj){
    Elemento aux;
    FILE *arq = fopen (nomeArq, "rb");
    int i;

    for(i=0; i<N; i++){
        fread(&aux, sizeof(struct elemento), 1, arq);

        if(aux->key == key){
            resp = (void*) malloc(sizeObj);
            memcpy(resp, aux->item, sizeObj);
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

void leituraCompleta(char * nomeArq){
    Elemento aux;
    FILE *arq = fopen(nomeArq, "rb");
    int i;

    for (i=0; i<N; i++){
        fread(&aux, sizeof(struct elemento), 1, arq);
        if(aux->key != -1)
            printf("%i\n", aux->key);
        else    
            printf("Disponivel - \n");
    }
    printf("\n");
    fclose(arq);
}