#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct{
	char name[40];
	int age;
}People;

struct Stack{
	int top;
	int tam;
	People *people;
};

void criar(struct Stack *stack, int tam);
void menu(struct Stack *stack);
void empilhar(struct Stack *stack, People people);
People desempilhar(struct Stack *stack);
void mostrar(struct Stack *stack);
int isVazio(struct Stack *stack);
int isFull(struct Stack *stack);

int main(void)
{
	struct Stack s;
	criar(&s, 5);
	menu(&s);
	return 0;
}

void criar(struct Stack *stack, int tam){
	stack->top = -1;
	stack->tam = tam;
	stack->people = (People*)malloc(sizeof(People));
}

void menu(struct Stack *stack){
	int choice = 6;
	People pessoa;
	while(choice!=0){
		system("cls");
		printf("Write your options:\n");
		printf("[1] - INSERT\n");
		printf("[2] - REMOVE\n");
		printf("[3] - LIST\n");
		printf("[4] - INVERTED LIST\n");
		printf("[0] - EXIT\n");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				system("cls");
				printf("Closed programa!\n");
				getch();
			break;
			
			case 1:
				if(!isFull(stack)){
					system("cls");
					printf("Digite o seu nome: \n");
					fflush(stdin);
					fgets(pessoa.name, 40, stdin);
					printf("Digite a sua idade: \n");
					scanf("%d", &pessoa.age);
					empilhar(stack, pessoa);
				}
				else{
					system("cls");
					printf("Pilha cheia!\n");
				}
				getch();
			break;
			
			case 3:
				if(!isVazio(stack)){
					system("cls");
					mostrar(stack);
				}
				else{
					system("cls");
					printf("Pilha vázia!\n");
				}
				getch();
			break;
			
			default:
				system("cls");
				printf("Opcao invalida!\n");
				getch();
			break;
		}
	}
}

void empilhar(struct Stack *stack, People people){
	stack->top++;
	strcpy(stack->people[stack->top].name, people.name);
	stack->people[stack->top].age = people.age;
}

People desempilhar(struct Stack *stack){
	People pessoa = stack->people[stack->top];
	stack->top--;
	return pessoa;
}

void mostrar(struct Stack *stack){
	int i = 0;
	for(i=stack->top; i>=0;i--)
	{
		printf("Nome: %s", stack->people[i].name);
		printf("Idade: %d", stack->people[i].age);
	}
}

int isVazio(struct Stack *stack){
	if(stack->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct Stack *stack){
	if(stack->top==stack->tam-1){
		return 1;
	}
	else{
		return 0;
	}
}
