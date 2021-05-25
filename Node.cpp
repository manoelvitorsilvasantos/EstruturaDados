#include<stdio.h>
#include<stdlib.h>


struct No{
	int valor;
	struct No *left;
	struct No *right;
};

typedef struct No no;

void criarArvore(No **pRaiz){
	*pRaiz = NULL;
}

void inserir(No **pRaiz, int valor2){
	if(*pRaiz == NULL){
		*pRaiz = (No*)malloc(sizeof(No));
		(*pRaiz)->left=NULL;
		(*pRaiz)->right=NULL;
		(*pRaiz)->valor=valor2;
	}
	else{
		if(valor2 <((*pRaiz)->valor))
		{
			inserir(&((*pRaiz)->left), valor2);
		}
		else{
			inserir(&((*pRaiz)->right), valor2);
		}
	}
}

int main(void){
	return 0;
}
