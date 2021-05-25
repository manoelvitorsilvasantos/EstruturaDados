#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

typedef struct Dados{
    char nome[50];
}DADOS;

typedef struct Arvore{
    DADOS dados;
    struct Arvore *esquerda, *direita;
}arv;

static const int verdade = 1;

//funcoes do tipo arv;
arv* iniciar();
arv* insere(arv *a, char nome[]);
arv* remover(arv *a, char nome[]);
arv* libera(arv *a);
//funcoes do tipo booleano
bool vazio(arv *a);
//funcoes do tipo integer
int buscar(arv *a, char *nome);
//procedimentos
void mostra(arv *a);
void menu(arv *a);

int main(void){
    arv *a = iniciar();
    menu(a);
}

void menu(arv *a){
    DADOS dados;
    int opc;

    while(verdade){
        system("cls");
        printf("[1] - INSERIR NOME \n");
        printf("[2] - REMOVER NOME \n");
        printf("[3] - MOSTRAR \n");
        printf("[4] - BUSCAR NOME \n");
        printf("[5] - LIBERA ARVORE \n");
        printf("[0] - SAIR \n");
        scanf("%d", &opc);

        switch(opc)
        {
            case 0:
                printf("Encerrado...\n");
                exit(0);
            break;
            
            case 1: //inserir
                system("cls");
                printf("Digite o nome: \n");
                fflush(stdin);
                gets(dados.nome);
                a = insere(a, dados.nome);
            break;

            case 2: //remover
                system("cls");
                if(!vazio(a)){
                    printf(">> Digite o nome para remover da arvore: \n");
                    fflush(stdin);
                    gets(dados.nome);
                    a = remover(a, dados.nome);
                    getch();
                }
                else{
                    printf("Arvore Vazia! \n");
                    getch();
                }
            break;
            
            case 3: //mostrar
                system("cls");
                if(!vazio(a)){
                    mostra(a);
                    getch();
                }
                else{
                    printf("Arvore Vazia! \n");
                    getch();
                }
            break;
            
            case 4: //buscar
                system("cls");
                if(!vazio(a)){
                    printf(">> Digite o nome da pessoa: \n");
                    fflush(stdin);
                    gets(dados.nome);
                    system("cls");
                    int sucesso = buscar(a, dados.nome);

                    if(sucesso == 0){
                        printf("Nenhum nome foi encontrado com essa descricao! \n");
                    }
                    else if(sucesso != 0){
                        printf("O nome [%s] foi encontrado na arvore! \n", dados.nome);
                    }
                    getch();
                }
                else{
                    printf("Arvore Vazia! \n");
                    getch();
                }
            break;
            
            case 5:
                system("cls");
                if(!vazio(a)){
                    a = libera(a);
                    printf("Raiz sem sub-arvores! \n");
                    getch();
                }
                else{
                    printf("Arvore Vazia! \n");
                    getch();
                }
            break;
            
            default: //alternativa fora das opcoes acima!
                system("cls");
                printf("Opcao invalida! \n");
                getch();
            break;
        }
    }
}

//funcoes do tipo arv;
//criar a raiz
arv* iniciar(){
    return NULL;
}
//funcao para inserir o nome na arvore
arv* insere(arv *a, char nome[]){
    //se a raiz nao possuir nós -> CRIA UM
    if(a == NULL){
        a = (arv*)malloc(sizeof(arv));
        strcpy(a->dados.nome, nome); //copia o nome recebido no paramento para o novo nó.
        a->esquerda = NULL; //ponteiro esquerdo da arvore aponta para NULO
        a->direita = NULL; //ponteiro direito da arvore aponta para NULO.
    } //senao vai adicionando novo no na sub-arvores
    else{
        /*
            Se o valor ao percorre arvore, a->nome <  nome
            adiciona a esquerda da arvore, caso contrario
            adiciona ao lado direito.
        */
        if(strcmp(a->dados.nome, nome) < 0){
            //a->esquerda = recebe o nome
            a->esquerda = insere(a->esquerda, nome);
        }
        else{
            //a->direita = e a mesma coisa que o 'a->esqueda'
            a->direita = insere(a->direita, nome);
        }
    }
    return a;
}

arv* remover(arv *a, char *nome){
   if(a == NULL){
		return NULL;
	}else{
	    
		if(strcmp(a->dados.nome, nome) > 0){
		    
			a->esquerda= remover(a->esquerda, nome);
			
		}else{
		    
			if(strcmp(a->dados.nome, nome) < 0 ){
			    
				a->direita = remover(a->direita, nome);
				
			}else{//achou o nó a remover
				if(a->esquerda == NULL && a->direita == NULL){//nó sem filho
					a = NULL;
					free(a);
					
				}else{//nó só tem filho à direita
				
					if(a->esquerda == NULL){
						arv* t = a;
						a = a->direita;
						free(t);
						
					}else{//nó só tem o filho à esquerda

                        if(a->direita == NULL){
						    
							arv* t = a;
							a = a->esquerda;
							free(t);
							
						}else{ //nó contém os dois filhos

                            arv* t = a->esquerda;
                            
							while(t->direita != NULL){
								t = t->direita;
							}
							
							strcpy(a->dados.nome, t->dados.nome);
							strcpy(t->dados.nome, nome);
							a->esquerda = remover(a->esquerda,nome);
							
						}
					}
				}
			}
		}
	}
    return a;
}

int buscar(arv *a, char *nome){
    int esq,dir;
    if(a == NULL)
        return 0;
    if(strcmp(a->dados.nome, nome) == 0){
        return 1;
    }
    if(strcmp(a->dados.nome, nome) < 0){
        esq = buscar(a->esquerda, nome);
    }
    else {
        dir = buscar(a->direita, nome);
    }
    return esq+dir;
}

arv* libera(arv *a){
    if(!vazio(a)){
        libera(a->esquerda);
        libera(a->direita);
        free(a);
    }
    return NULL;
}
//funcoes do tipo booleano
bool vazio(arv *a){
    if(a == NULL){
        return true;
    }
    else{
        return false;
    }
}

//procedimentos
void mostra(arv *a){

    printf("<");
    if(!vazio(a)){
        printf("-[%s]", a->dados.nome);
        mostra(a->esquerda);
        mostra(a->direita);
    }
    printf(">");
}


