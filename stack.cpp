#include<stdio.h>
#include<stdlib.h>

//strutura de dados da pilha.
struct pilha{
  int *item;
  int tamanho;
  int topo;
};


//prototipos da pilha
void create(struct pilha *p, int tamanho);
void insert(struct pilha *p, int item);
int remover(struct pilha *p);
void showValeus(struct pilha *p);
int emptyStack(struct pilha *p);
int fullStack(struct pilha *p);
int choiceMenu(struct pilha *p);

int main(void){

  struct pilha p;
  int tam;
  printf("Write size of the stack: \n");
  scanf("%d", &tam);
  create(&p, tam);
  choiceMenu(&p);
  return 0;
}

//menu de escolha
int choiceMenu(struct pilha *p){
  //inicia pra não pular o while.
  int choiceOptions= 4;
  int valor = 0;

//verifica se a alternativa seja diferente de zero,
//caso contrario continua
  while(choiceOptions != 0){
		printf("%s %s %s %s",
			"\n[1] - INSERT\n",
			"\n[2] - REMOVE\n",
			"\n[3] - Show Values\n",
			"\n[0] - EXIT\n"
		);
		scanf("%d", &choiceOptions);
		switch(choiceOptions){
			case 0:
				printf("Close application\n");
				getchar();
				break;
			case 1:
				valor = 0;
				if(!fullStack(p)){
					printf("Write the value:\n");
					scanf("%d", &valor);
					insert(p, valor);
					getchar();
				}
				else{
					printf("Full Stack!\n");
          getchar();
				}
				break;
			case 2:
				valor = 0;
				if(!emptyStack(p)){
					valor = remover(p);
					printf("Item %d was removed!\n", valor);
					getchar();
				}
				else{
					printf("Empty Stack!\n");	
          getchar();
				}
				break;
			case 3:
				if(!emptyStack(p)){
					printf("List values of the Stack: \n");
					showValeus(p);
				}
				else{
					printf("Empty Stack!\n");	
          getchar();
				}
				break;
			default:
				printf("Options Invalid!\n");
        getchar();
				break;
		}
  }
}

//funcao que cria a pilha.
//MAKE ONE STACK
void create(struct pilha *p, int tamanho){
  //inicia o topo com -1
	p->topo = -1;
  //dá o tamanho da pilha, passado pela parametro tamanho.
	p->tamanho = tamanho;
  //aloca na memoria do computador um vetor com o tamanho especificado pelo usuario.
	p->item = (int*)calloc(tamanho, sizeof(int));
}
//funcao que insere o valor no topo da pilha.
//INSERT TO STACK
void insert(struct pilha *p, int item){
  //incrementa o topo
	p->topo++;
  //atribui aquela posicao incrementa ao valor inserido.
	p->item[p->topo] = item;
}

//funcao que remove o valor do top da pilha e o retorna.
//REMOVE TO STACK
int remover(struct pilha *p){
  //guarda o valor removido
	int valorRemovido = p->item[p->topo];
  //decrementa
	p->topo--;
  //retorna o valor removido, guardado em valorRemovido.
	return valorRemovido;
}

//mostra os valores da pilha
//SHOW VALUES TO STACK
void showValeus(struct pilha *p){
	int i;
  //impre os valores do vetor.
	for(i = p->topo; i >= 0; i--){
		printf("%d\n", p->item[i]);
	}
}
//verifica se a pilha esta vazia.
//IF IS EMPTY
int emptyStack(struct pilha *p)
{

  //se o topo for o valor iniciado na funcao criacao, significa que a pilha
  //esta vazia.
  //retorna 1 se for verdade ou 0 se for falso.
	if(p->topo==-1){
		return 1;
	}
	else{
		return 0;
	}
}

//verifica se a pilha esta cheia.
//IF IS FULL
int fullStack(struct pilha *p){

  //verifica se o topo da pilha e igual ao valor do variavel tamanho-1.
  //isso porque a pilha inicia do zero. 
	if(p->topo == p->tamanho-1){
		return 1;
	}
	else{
		return 0;
	}
}

int getTopoValor(struct pilha *p){
	int valor = p->topo;
	
}


