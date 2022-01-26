#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashingGen.h"
#define N 10

typedef struct elemento{
    int tipo,key;
    void *item;
}*Elemento;

void InicializaArq(char *nomeArq, void *obj, int sizeOvj){
    FILE *arq = fopen(nomeArq,"wb");
    Elemento aux=(Elemento) malloc(sizeof(struct elemento));

    aux->item=obj;
    aux->tipo=-1;
    aux->key=-1;

    for(int i=0;i<N;i++)
        fwrite(aux,sizeof(struct elemento),1,arq);

    fclose(arq);
}

int hash(int key){
    return key%N;
}

int AcharPosicao(char *nomeArq, int key, int sizeObj){
    FILE *arq=fopen(nomeArq,"rb");
    int pos=hash(key);

    Elemento aux=(Elemento) malloc(sizeof(struct elemento));

    fseek(arq,pos*sizeof(struct elemento),SEEK_SET);
    fread(aux,sizeof(struct elemento),1,arq);

    while(aux->key !=-1){
        pos=(pos+1) %N;
        fseek(arq,pos*sizeof(struct elemento),SEEK_SET);
        fread(aux,sizeof(struct elemento),1,arq);
    }
    
    fclose(arq);
    return pos;
}

void Inserir(char *nomeArq,int key, void *objeto, int sizeObj){
    int pos = AcharPosicao(nomeArq, key, sizeObj);

    FILE *arq=fopen(nomeArq, "r+b");

    Elemento aux=(Elemento) malloc(sizeof(struct elemento));
    //memcpy(aux->item,objeto,sizeObj);
    aux->item=objeto;
    aux->key=key;

    fseek(arq,pos*sizeof(struct elemento),SEEK_SET);
    fwrite(aux,sizeof(struct elemento),1,arq);
    fclose(arq);
}

int BuscarObj(char *nomeArq, int key, void *obj, int sizeObj){
    FILE *arq=fopen(nomeArq,"rb");
    Elemento aux=(Elemento) malloc(sizeof(struct elemento));

    int pos=hash(key);
    fseek(arq,pos*sizeof(struct elemento),SEEK_SET);

    fread(aux,sizeof(struct elemento),1,arq);
    printf("\n%d %d %d\n",key,aux->key,pos);
    if(aux->key==key){
        obj=aux->item;
        return 1;
    }else{
        int vrf=0;
        for(int i=pos;i<N;i++){
            fread(aux,sizeof(struct elemento),1,arq);

            if(aux->key==key){
                obj=aux->item;
                return 1;
            }

            if(pos==N-1 && vrf==0){
                pos=0;
                vrf=1;
            }
        }
    }
    fclose(arq);
    return 0;
}

void leituraCompleta(char *nomeArq){
    Elemento aux=(Elemento) malloc(sizeof(struct elemento));
    FILE *arq=fopen(nomeArq,"rb");
    for(int i=0;i<N;i++){
        fread(aux,sizeof(struct elemento),1,arq);
        if(aux->key != -1)
            printf("%d\n",aux->key);
        else
            printf("Disponivel \n");
    }
    printf("\n");
    fclose(arq);
}