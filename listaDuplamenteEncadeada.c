#include<stdio.h>
#include<stdlib.h>


typedef struct elemento Elemento;

struct elemento{
	int valor;
	Elemento *proximo;
	Elemento *anterior;
};

Elemento *inicio;
Elemento *fim;


int tamanho;

// Criando prototipos de função
void criarLista();
Elemento *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void inserePosicao(int valor, int posicao);
void removeInicio();
void removeFim();
void imprimeLista();
void imprimeListaContrario();

int main(void){
	
	criarLista();
	
	int valor = 0;
	int posicao = 0;
	int opc = 8;
	while(opc != 0){
		printf("[DIGITE A OPCAO]\n");
		printf("[1] INSERTIR INICIO\n");
		printf("[2] INSERTIR FIM\n");
		printf("[3] INICIO EM NA POSICAO\n");
		printf("[4] REMOVER INICIO\n");
		printf("[5] REMOVER FINAL\n");
		printf("[6] LISTA NORMAL\n");
		printf("[7] LISTA INVERTIDA\n");
		printf("[0] SAIR\n");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 0:
				break;
			case 1:
				printf("Digite o valor:\n");
				scanf("%d", &valor);
				insereInicio(valor);
				break;
			case 2:
				printf("Digite o valor:\n");
				scanf("%d", &valor);
				insereFim(valor);
				break;
			case 3:
				printf("Digite o valor:\n");
				scanf("%d", &valor);
				printf("Digite a posicao:\n");
				scanf("%d", &posicao);
				inserePosicao(valor, posicao);
				break;
			default:
				printf("OPCAO INVALIDA!\n");
			break;
		}
	}
	
	return 0;
}

// Criando prototipos de função
void criarLista(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

//aloca novo dado.
Elemento *aloca(int valor){
	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

void insereInicio(int valor){
	Elemento *novo  = aloca(valor);
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	}
	else{
		Elemento *atual;
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}

void insereFim(int valor){
	Elemento *novo = aloca(valor);
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	}
	else{
		Elemento *atual;
		atual = fim;
		novo->anterior = atual;
		atual->proximo = novo;
		fim = novo;
	}
	tamanho++;
}

void inserePosicao(int valor, int posicao){
	posicao = posicao-1;
	Elemento *novo = aloca(valor);
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	}
	else{
		Elemento *atual;
		Elemento *tmp;
		int i;
		if(posicao < (tamanho/2)){
			atual = inicio;
			i = 0;
		}
		else{
			atual = fim;
			i = tamanho;
		}
		
		while ((i != posicao) && (i >= 0) && (i <= tamanho)){
			if(i < posicao){
				i++;
				atual = atual->proximo;
			}
			else if(i > posicao){
				i--;
				atual = atual->anterior;
			}
			
			if(posicao == 1){
				printf("valor antecessor %d\n", atual->anterior->valor);
				printf("valor proximo %d\n", atual->proximo->valor);
			}
		}
	}
}

void removeInicio(){
	Elemento *atual=inicio;
	inicio=atual->proximo;
	inicio->anterior = NULL;
	tamanho--;
}

void removeFim(){
	Elemento *atual=fim;
	fim=atual->anterior;
	fim->proximo = NULL;
	tamanho--;
}

void imprimeLista(){
	Elemento *atual;
	atual = inicio;
	while(atual){
		printf("%d\n", atual->valor);
		atual = atual->proximo;
	}
}

void imprimeListaContrario(){
	Elemento *atual;
	atual = fim;
	while(atual){
		printf("%d\n", atual->valor);
		atual = atual->anterior;
	}
}


