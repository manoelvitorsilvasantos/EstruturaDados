#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dados{
	char nome[40];
};


struct pilha{
	int topo;
	int tamanho;
	struct dados *item;
};

void menu(struct pilha *p);
void criar(struct pilha *p, int tamanho);
void inserir(struct pilha *p, struct dados item);
struct dados remover(struct pilha *p);
void mostrar(struct pilha *p);
void mostrarInvertido(struct pilha *p);
int cheio(struct pilha *p);
int vazio(struct pilha *p);


int main(void){
	struct pilha p;
	criar(&p, 5);
	menu(&p);
	return 0;
}


void menu(struct pilha *p){
	int opcao = 6;
	struct dados data;
	while(opcao != 0){
		system("cls");
		printf("[DIGITE UMA ESCOLHA]\n");
		printf("[1] - INSERIR\n");
		printf("[2] - REMOVER\n");
		printf("[3] - MOSTRAR\n");
		printf("[4] - MOSTRAR INVERTIDO\n");
		printf("[0] - SAIR\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				system("cls");
				printf("Fechando programa!\n");
				getchar();
			break;
			
			case 1:
				if(!cheio(p)){
					system("cls");
					printf("Digite o seu nome: \n");
					fflush(stdin);
					fgets(data.nome, 40, stdin);
					inserir(p, data);
					printf("Inserido com sucesso!\n");
					printf("----------------------------------");
				}
				else{
					system("cls");
					printf("Pilha cheia!\n");
				}
				printf("Aperte [ENTER] 2x p/ sair!!!\n");
				getchar();
				getchar();
			break;
			
			case 2:
				if(!vazio(p)){
					system("cls");
					data = remover(p);
					printf("Nome: %s foi removido!\n", data.nome);
				}
				else{
					system("cls");
					printf("Pilha vazia!\n");
				}
				printf("Aperte [ENTER] p/ sair!!!\n");
				getchar();
				getchar();
			break;
			
			case 3:
				if(!vazio(p)){
					system("cls");
					mostrar(p);
				}
				else{
					system("cls");
					printf("Pilha vazia!\n");
				}
				printf("Aperte [ENTER] 2x p/ sair!!!\n");
				getchar();
				getchar();
			break;
			
			case 4:
				if(!vazio(p)){
					system("cls");
					mostrarInvertido(p);
				}
				else{
					system("cls");
					printf("Pilha vazia!\n");
				}
				printf("Aperte [ENTER] 2x p/ sair!!!\n");
				getchar();
				getchar();
			break;
			
			default:
				system("cls");
				printf("Opcao invalida!\n");
				printf("Aperte [ENTER] p/ sair!!!\n");
				getchar();
				getchar();	
			break;
		}
	}
}

void criar(struct pilha *p, int tamanho){
	p->topo = -1;
	p->tamanho = tamanho;
	p->item = (struct dados*)malloc(sizeof(struct dados));
}

void inserir(struct pilha *p, struct dados item){
	p->topo++;
	//p->item[p->topo] = item;
	strcpy(p->item[p->topo].nome, item.nome);
}

struct dados remover(struct pilha *p){
	struct dados valor = p->item[p->topo];
	p->topo--;
	return valor;
}

void mostrar(struct pilha *p)
{
	int i = 0;
	printf("\n\nInicio\n");
	printf("--------------------------\n");
	for(i = p->topo; i >= 0; i--){
		printf("%s\n", p->item[i].nome);
	}
	printf("--------------------------\n");
	printf("\n\nFinal\n");
	getchar();
}


void mostrarInvertido(struct pilha *p){
	int i = 0;
	printf("\n\nInicio\n");
	printf("--------------------------\n");
	for(i = 0; i <= p->topo; i++){
		printf("%s\n", p->item[i].nome);
	}
	printf("--------------------------\n");
	printf("\n\nFinal\n");
	getchar();
}

int vazio(struct pilha *p){
	if(p->topo == -1){
		return 1;
	}
	else{
		return 0;
	}
}


int cheio(struct pilha *p){
	if(p->topo == p->tamanho-1){
		return 1;
	}
	else{
		return 0;
	}
}



