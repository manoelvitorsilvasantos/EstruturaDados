#include<stdio.h>
#include<stdlib.h>


struct No{
	int valor;
	struct No *proximo;
};

void criar(struct No **no){
	no = NULL;
}

int inserirInicio(struct No **no, int valor);
int inserirFinal(struct No **no, int valor);
void removerInicio(struct No **no);
void removerFinal(struct No **no);
void mostrar(struct No *no);

int main(void){
	struct No *no;
	criar(&no);
	inserirInicio(&no, 30);
	mostrar(no);
	return 0;
}

int inserirInicio(struct No **no, int valor){
	struct No *novo;
	novo = (struct No*)malloc(sizeof(struct No));
	if(novo==NULL){
		printf("Falta memoria!\n");
		return -1;
	}
	novo->valor = valor;
	
	novo->proximo = *no;
	*no = novo;
}
/*
void inserirFinal(struct No **no, int valor){
	node *novo;
	node *atual;
	
	novo=(node*)malloc(sizeof(node));
}

void removerInicio(struct No **no){
	
}

void removerFinal(struct No **no)
{
	
}
*/
void mostrar(struct No *no){
	if(no == NULL) printf("\nLista vazia");
    else{
        struct No *p_Atual_Corredor, *p_Atual_Fim;
        p_Atual_Corredor = no;
        p_Atual_Fim = no;
        while(p_Atual_Fim->proximo != NULL){ //ir para o ultimo elemento
            p_Atual_Fim = p_Atual_Fim->proximo;
        }
        while(p_Atual_Corredor != p_Atual_Fim){
            if(p_Atual_Corredor->proximo == p_Atual_Fim){
                printf(" <- %d", p_Atual_Fim->valor);
                p_Atual_Fim = p_Atual_Corredor;
                p_Atual_Corredor = no;
            }
            else p_Atual_Corredor = p_Atual_Corredor->proximo;
        }
        printf(" <- %d", p_Atual_Fim->valor);
    }
}

