<<<<<<< HEAD
#ifndef  HashGen_H
#define HashGen_H

typedef struct aluno *Aluno;
typedef struct professor *Professor;
typedef struct pessoa Pessoa;

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj);
Buscar();
void Printa(Pessoa *p, int size);


=======
#ifndef  HashGen_H
#define HashGen_H

typedef struct aluno *Aluno;
/*
Quando você define o typedef com
 struct algo *Algo
 Esse * simboliza que o Algo, é um ponteiro de struct algo, então lá na main quando vc chamar vc só chama Algo ;)
*/
typedef struct professor *Professor;
typedef struct pessoa Pessoa;

void Inserir(char *nomeArq, int key, void *objeto, int sizeObj);
Buscar();
void Printa(Pessoa *p, int size);


>>>>>>> 6b26dbf95d884519be2ef2e6f29b8a335fee08ae
#endif