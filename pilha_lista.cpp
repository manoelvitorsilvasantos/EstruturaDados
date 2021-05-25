#include<stdio.h>
#include<stdlib.h>


typedef struct lista{
	int valor;
	struct lista *proximo;
}Lista;

typedef struct listaInicio
{
	Lista *inicio;
	int tamanho;
}Pilha;

void criar(Pilha *p){
	p->inicio = NULL;
	p->tamanho = 0;
}
