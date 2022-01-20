#ifndef  HashGen_H
#define HashGen_H

typedef struct aluno *Aluno;
typedef struct professor *Professor;
typedef struct pessoa Pessoa;

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj);
Buscar();
void Printa(Pessoa *p, int size);


#endif