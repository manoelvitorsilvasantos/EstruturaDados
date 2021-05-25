/*
	Componentes -> 
		Gustavo 
		Lucas
		Manoel Vitor
	Tutora
		Lais farias alves
	Turma 
		Ads 2 semestre


*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Data{
	int dia, mes, ano;
};

struct Endereco{
	char logradouro[50], complemento[15], bairro[15], cep[15], cidade[15], estado[15];
	int numero;
};

struct Dados_Pessoais{
	char nome[50], tel[15], cel[15], email[50];
	
};

typedef struct Aluno{
	struct Dados_Pessoais pes;	
	char matricula[8],serie[2], turma[3], turno[4];
	struct Endereco end;
	struct Data da;
}aluno;

typedef struct Professor{
	struct Dados_Pessoais pes;
	char matricula[8], formacao[30], discip1[30], discip2[30];
	struct Endereco end;
	struct Data da;
}professor;

void cadastrar_professor(void);
void listar_professor(void);
void cadastrar_aluno(void);
void listar_aluno(void);


int main(){
		
	FILE* aluno_file, *professor_file;
	int opc;

	
	while(1){
		
		system("cls");
		printf("\n\n[1] - CADASTRAR PROFESSOR \n");
		printf("[2] - LISTAR PROFESSOR \n");
		printf("[3] - CADASTRAR ALUNO \n");
		printf("[4] - LISTAR ALUNO \n");
		printf("[0] - SAIR \n");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 0://sair
				exit(1);
				break;
			case 1: // cadastrar professor
			
				system("cls");
				cadastrar_professor();
				getch();
			
			break; // listar professores
			
			case 2:
				
				system("cls");
				listar_professor();
				getch();
				
			break;
				
			case 3: // cadastrar ALUNOS
				system("cls");
				cadastrar_aluno();
				getch();
				
			break;
				
			case 4: // listar professores
				system("cls");
				listar_aluno();
				getch();
				
			break;
				
			default:
				
				system("cls");
				printf("Opcao invalida! \n");
				getch();
			break;
		}
		
	}
	
	fclose(aluno_file);
	fclose(professor_file);

	
	return 0;	
}

void cadastrar_professor(void){
	
	FILE* arq_pr;
	professor pr;
	
	arq_pr = fopen("data_professor.bin", "a+b");
	
	if(arq_pr == NULL){
		system("cls");
		printf("Erro, de leitura! \n");
		fclose(arq_pr);
		getch();
		exit(1);
	}
	else{
		
		printf("===== DIGITE OS SEUS DADOS ======\n");
		//dados pessoais
		printf("NOME:\n");
		fflush(stdin);
		gets(pr.pes.nome);
		
		printf("DN \n");
		printf("Dia -> \b");
		scanf("%d", &pr.da.dia);
		printf("\n");
		printf("Mes -> \b");
		scanf("%d", &pr.da.mes);
		printf("\n");
		printf("Ano -> \b");
		scanf("%d", &pr.da.ano);
		printf("\n");
		
		printf("TELEFONE: \n ");
		fflush(stdin);
		gets(pr.pes.tel);
		
		printf("\n");
		printf("CELULAR:\n");
		fflush(stdin);
		gets(pr.pes.cel);
		
		printf("\n");
		printf("E-MAIL:\n");
		fflush(stdin);
		gets(pr.pes.email);
		
		printf("\n");
		//dados academicos
		printf("FORMACAO:\n");
		fflush(stdin);
		gets(pr.formacao);
		
		printf("MATRICULA 8 dig. maximo:\n");
		fflush(stdin);
		gets(pr.matricula);
		
		printf("DISCIPLINA I:\n");
		fflush(stdin);
		gets(pr.discip1);
		
		printf("DISCIPLINA II:\n");
		fflush(stdin);
		gets(pr.discip2);
		
		//dados de localizacao
		printf("LOGRADOURO:\n");
		fflush(stdin);
		gets(pr.end.logradouro);
		
		printf("BAIRRO:\n");
		fflush(stdin);
		gets(pr.end.bairro);
		
		printf("COMPLEMENTO:\n");
		fflush(stdin);
		gets(pr.end.complemento);
		
		printf("ESTADO - SIGLA:\n");
		fflush(stdin);
		gets(pr.end.estado);
		strupr(pr.end.estado);
		
		printf("NUMERO:\n");
		scanf("%d", &pr.end.numero);
		
		printf("CEP:\n");
		fflush(stdin);
		gets(pr.end.cep);
		
		printf("CIDADE:\n");
		fflush(stdin);
		gets(pr.end.cidade);
		
	
		fwrite(&pr, sizeof(Professor), 1, arq_pr);		
		
	}
	fclose(arq_pr);
	
}

void listar_professor(void){
	
	FILE* arq_pr;
	professor pr;
	
	arq_pr = fopen("data_professor.bin", "rb");
	
	if(arq_pr == NULL){
		system("cls");
		printf("Erro, de leitura! \n");
		fclose(arq_pr);
		getch();
		exit(1);
	}
	else{
		
	
		printf("\n=============== LISTA DE PROFESSOR =============\n\n");
		
		while(fread(&pr, sizeof(professor), 1, arq_pr) == 1){
			
			//dados pessoais
			printf("NOME: %s\n", pr.pes.nome);
			printf("DN: %d/%d/%d\n", pr.da.dia, pr.da.mes, pr.da.ano);
			printf("CELULAR: %s\n", pr.pes.cel);
			printf("TELEFONE: %s\n", pr.pes.tel);
			printf("E-MAIL: %s\n", pr.pes.email);
			
			// formacao
			printf("FORMACAO: %s \n", pr.formacao);
			printf("DISCIPLINA I: %s \n", pr.discip1);
			printf("DISCIPLINA II: %s \n", pr.discip2);
			printf("MATRICULA: %s \n", pr.matricula);
			
			//enderecos
			printf("LOGRADOURO: %s \n", pr.end.logradouro);
			printf("BAIRRO: %s \n", pr.end.bairro);
			printf("COMPLEMENTO: %s \n", pr.end.complemento);
			printf("NUMERO: %d \n", pr.end.numero);
			printf("CEP: %s \n", pr.end.cep);
			printf("CIDADE: %s\n", pr.end.cidade);	
			printf("ESTADO: %s \n", pr.end.estado);
			printf("\n==================================================\n");
				
		}
		
		fclose(arq_pr);
	}
	
}

void cadastrar_aluno(void){
	
	FILE* arq_al;
	aluno al;
	
	arq_al = fopen("data_aluno.bin", "a+b");
	
	if(arq_al == NULL){
		system("cls");
		printf("Erro, de leitura! \n");
		fclose(arq_al);
		getch();
		exit(1);
	}
	else{
		
		
		printf("===== DIGITE OS SEUS DADOS ======\n");
		
		//DADOS PESSOAIS
		printf("NOME: \n");
		fflush(stdin);
		gets(al.pes.nome);
		
		printf("DN - Digite a Data de Nascimento:\n");
		printf("DIA ->  \b");
		scanf("%d", &al.da.dia);
		
		printf("\nMES ->  \b");
		scanf("%d", &al.da.mes);
		
		printf("\nANO ->  \b");
		scanf("%d", &al.da.ano);
		printf("\n");
		
		printf("MATRICULA - 8 Digitos do maximo: \n");
		fflush(stdin);
		gets(al.matricula);
		
		printf("SERIE - 4 digitos: \n");
		fflush(stdin);
		gets(al.serie);
		
		printf("TURMA - 4 digitos: \n");
		fflush(stdin);
		gets(al.turma);
		
		printf("TURNO - SIGLA: \n");
		fflush(stdin);
		gets(al.turno);
		
		
		printf("E-MAIL: \n");
		fflush(stdin);
		gets(al.pes.email);
		
		printf("TELEFONE: \n");
		fflush(stdin);
		gets(al.pes.tel);
		
		printf("CELULAR: \n");
		fflush(stdin);
		gets(al.pes.cel);
		
		//endereco
		
		printf("LOGRADOURO: \n");
		fflush(stdin);
		gets(al.end.logradouro);
		
		printf("BAIRRO: \n");
		fflush(stdin);
		gets(al.end.bairro);
		
		printf("COMPLEMENTO: \n");
		fflush(stdin);
		gets(al.end.complemento);
		
		printf("CEP: \n");
		fflush(stdin);
		gets(al.end.cep);
		
		printf("NUMERO: \n");
		scanf("%d", &al.end.numero);
		
		printf("CIDADE: \n");
		fflush(stdin);
		gets(al.end.cidade);
		
		printf("ESTADO SIGLA: \n");
		fflush(stdin);
		gets(al.end.estado);
		strupr(al.end.estado);
		
		fwrite(&al, sizeof(aluno), 1, arq_al);	
		
			
	}
	
	fclose(arq_al);
	
}

void listar_aluno(void){
	
	FILE* arq_al;
	aluno al;
	
	arq_al = fopen("data_aluno.bin", "rb");
	
	if(arq_al == NULL){
		system("cls");
		printf("Erro, de leitura! \n");
		fclose(arq_al);
		getch();
		exit(1);
	}
	else{
		
	
		printf("\n=============== LISTA DE ALUNOS =============\n\n");
		
		while(fread(&al, sizeof(aluno), 1, arq_al) == 1){
			
			//dados pessoais
			printf("NOME: %s \n", al.pes.nome);
			printf("DN: %d/%d/%d \n", al.da.dia, al.da.mes, al.da.ano);
			printf("CELULAR: %s \n", al.pes.cel);
			printf("TELEFONE: %s \n", al.pes.tel);
			printf("E-MAIL: %s\n", al.pes.email);
			
			// formacao
			printf("MATRICULA: %s \n", al.matricula);
			printf("SERIE: %s \n", al.serie);
			printf("TURMA: %s \n", al.turma);
			printf("TURNO: %s \n", al.turno);
			
			//enderecos
			printf("LOGRADOURO: %s \n", al.end.logradouro);
			printf("BAIRRO: %s \n", al.end.bairro);
			printf("COMPLEMENTO: %s \n", al.end.complemento);
			printf("NUMERO: %d \n", al.end.numero);
			printf("CEP: %s \n", al.end.cep);
			printf("CIDADE: %s\n", al.end.cidade);	
			printf("ESTADO: %s \n", al.end.estado);
			printf("\n==================================================\n");		
		}
		
		fclose(arq_al);
		
	}
	
	
}
