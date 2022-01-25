#ifndef  HashGen_H
#define HashGen_H

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj);
void InicializaArq(char *nomearq, void *obj, int sizeObj);
int BuscarObj(char *nomeArq, int key, void*resp, int sizeObj);
void leituraCompleta(char *nomeArq);

#endif