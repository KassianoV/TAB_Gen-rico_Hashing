#include<stdio.h>
#include<stdlib.h>
#include"HashingGen.h"
#include<string.h>
#define N 15

typedef struct elemento{ 
    int tipo;   
    int key;      
    void *item;
}*Elemento;

void InicializaArq(char *nomeArq, void *obj, int sizeObj){
    FILE *arq = fopen(nomeArq,"wb");
    Elemento a=(Elemento) malloc(sizeof(struct elemento));

    a->item=obj;
    a->tipo=-1;
    a->key=-1;

    for(int i=0; i<N; i++)
        fwrite(&a, sizeof(struct elemento),1,arq);

    fclose(arq);
}

int hash(int key){
    return key%N;
}

int AcharPosicao(char *nomeArq, int key,int sizeObj){
    FILE *arq = fopen(nomeArq, "rb");
    int pos=hash(key);
    printf("%d",pos);
    
    Elemento aux;//=(Elemento) malloc(sizeof(struct elemento));
    fseek(arq, pos * sizeof(struct elemento), SEEK_SET);
    fread(aux, sizeof(struct elemento), 1,arq);

    while (aux->key == -1){
        pos = (pos+1) % N;
        fseek(arq, pos *sizeof(struct elemento), SEEK_SET);
        fread(aux, sizeof(struct elemento),1, arq);
    }
    fclose(arq);
    return pos;
}

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj){
    int pos = AcharPosicao(nomeArq, key, sizeObj);
    Elemento aux=(Elemento) malloc(sizeof(struct elemento));

    FILE *arq = fopen(nomeArq, "r+b");
    aux->item = (void*) malloc(sizeObj);
    memcpy(aux->item, objeto, sizeObj);

    aux->key = key;
    fseek(arq, pos*sizeof(struct elemento), SEEK_SET);

    fwrite(&aux, sizeof(struct elemento),1,arq);
    fclose(arq);
}

int BuscarObj(char *nomeArq, int key, void *resp, int sizeObj){
	FILE *arq=fopen(nomeArq,"rb");
	Elemento aux=(Elemento) malloc(sizeof(struct elemento));
	int pos=hash(key);
	fseek(arq,pos*sizeof(struct elemento),SEEK_SET);

	fread(aux,sizeof(struct elemento),1,arq);
	if(aux->key==key){
		resp=aux->item;
		return 1;
	}else{
		int vrf=0;
		for(int i=pos;i<N;i++){
			fread(aux,sizeof(struct elemento),1,arq);
			if(aux->key!=-1){
				resp=aux->item;
				return 1;
			}
			if(pos==N-1 && vrf==0){
				pos=0;
				vrf=1;
			}
		}
	}
	return 0;
}
void leituraCompleta(char *nomeArq){
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
