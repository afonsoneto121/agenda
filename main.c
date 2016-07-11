#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "tipo.h"

#define MAX_NOME 100
#define MAX_TEL 11
#define MAX_EMAIL 100
#define MAX_TIPO 50

int inicio()
{
	int op;
	//AGENDA
	printf("###################################### \n");
	printf("#------------------------------------# \n");	
	printf("#               AGENDA               # \n");
	printf("#------------------------------------# \n");
	printf("###################################### \n");

	printf("\n");
	printf("Digite:\n");
	printf("1 Para Adicionar Novo contato\n");
 	printf("2 Para Excluir contato\n");
 	printf("3 Para Listar contato\n");
 	printf("4 Para Busca contato\n");
 	printf("5 Para Alterar contato\n");
 	printf("6 Para tipo de contato\n");
 	printf("7 Para Sair\n");
 	scanf("%d",&op);
	
	return op;
}
int menu()
{
	int op;
	printf("\n");
	printf("Digite:\n");
	printf("1 Para Adicionar Novo contato\n");
 	printf("2 Para Excluir contato\n");
 	printf("3 Para Listar contato\n");
 	printf("4 Para Busca contato\n");
 	printf("5 Para Alterar contato\n");
 	printf("6 Para tipo de contato\n");
 	printf("7 Para Sair\n");
 	scanf("%d",&op);
	
	return op;	
}
void excluir_contato(ListaE* l) 
{
	char *numero_telefone = (char*) malloc(MAX_TEL *sizeof(char));
	printf("Digite o numero do contato\n");
	scanf("%s",numero_telefone);
	remover(l, numero_telefone);
	
}
Agenda* adicionar_novo_contato(Tipo *p)
{
	char *nome_completo = (char*) malloc(MAX_NOME *sizeof(char));
	char *numero_telefone = (char*) malloc(MAX_TEL *sizeof(char));
	char *email = (char*) malloc(MAX_EMAIL *sizeof(char));
	char *tipo = (char*) malloc(MAX_TIPO *sizeof(char));

	printf("Digite seu nome: \n");
	scanf("%s",nome_completo);
	printf("Digite seu telefone(Somente Numero): \n");
	scanf("%s",numero_telefone);
	printf("Digite seu email: \n");
	scanf("%s",email);
	printf("Digite o tipo de contato: \n");
	imprimir_tipo(p);
	scanf("%s",tipo);
	printf("%s,%s,%s,%s\n", nome_completo,numero_telefone,email,tipo);
	Agenda *novo = criar_agenda(nome_completo,numero_telefone,email,tipo);
	return novo;
	
}
void listar_contatos(ListaE *l)
{
	le_imprimi(l);
}
void buscar_contato(ListaE *l)
{
	char *numero_telefone = (char*) malloc(MAX_TEL *sizeof(char));
	printf("Digite o numero do contato\n");
	scanf("%s",numero_telefone);

	if (le_buscar(l,numero_telefone) != NULL)
	{
		printf("Contato encontrado \n");
	}
	else
		printf("Contato não encontrado\n");

}
Agenda* alterar_contato(ListaE* l,Tipo *p)
{
	char *numero_tel = (char*) malloc(MAX_TEL *sizeof(char));
	printf("Digite o numero do contato\n");
	scanf("%s",numero_tel);

	if (le_buscar(l,numero_tel) != NULL)
	{
		printf("Contato encontrado \n");
		printf("Alterar para ..\n");
		char * tel  = numero_tel;
		remover(l,tel);

		char *nome_completo = (char*) malloc(MAX_NOME *sizeof(char));
		char *numero_telefone = (char*) malloc(MAX_TEL *sizeof(char));
		char *email = (char*) malloc(MAX_EMAIL *sizeof(char));
		char *tipo = (char*) malloc(MAX_TIPO *sizeof(char));
		strcpy(numero_telefone,tel);

		printf("Digite seu nome: \n");
		scanf("%s",nome_completo);
		printf("Digite seu email: \n");
		scanf("%s",email);
		printf("Digite o tipo de contato: \n");
		imprimir_tipo(p);
		scanf("%s",tipo);
		printf("%s,%s,%s,%s\n", nome_completo,numero_telefone,email,tipo);
		Agenda *novo = criar_agenda(nome_completo,numero_telefone,email,tipo);
		return novo;
		}
	else
	{
		printf("Contato não encontrado\n");
		return NULL;
	}
	
	
	
	
}

int tipo_contato()
{
	int op;
	
	
	printf("\n");
	printf("Digite:\n");
	printf("1 Para Adicionar Novo tipo\n");
 	printf("2 Para listar tipos\n"); 	

 	scanf("%d",&op);
	
	return op;
}
char* adicionar_tipo()
{
	printf("Digite o nome do tipo\n");
	char *nome = (char*) malloc(50 *sizeof(char));
	scanf("%s",nome);
	return nome;
}

int main(int argc, char const *argv[])
{
	Tipo *p = tipo_criar();
	ListaE *l = le_criarLista();
	int op = 0;
	ler_arquivo(l);
	ler_arquivo_tipo(p);
	op = inicio();
	while(op != 7)
	{
		if(op == 1)
		{
			Agenda *agenda = adicionar_novo_contato(p);
			le_inserir(l,agenda);
		}
		else if(op == 2)
		{
			//Excluir contato
			excluir_contato(l);
		}
		else if(op == 3)
		{
			//Listar Contatos
			listar_contatos(l);
		}
		else if(op == 4)
		{
			//Buscar Contato
			buscar_contato(l);
		}
		else if(op == 5)
		{
			//Alterar Contato
			Agenda *agenda = alterar_contato(l,p);
			le_inserir(l,agenda);
		}
		else if(op == 6)
		{
			//Tipo de Contato
			 int c = tipo_contato();
			 if(c == 1)
			 {
			 	char *c = adicionar_tipo();
			 	tipo_novo(p,c);
			 }
			 else if(c==2)
			 {
			 	imprimir_tipo(p);
			 }
		}

		op = menu();

	}
	abrir_arquivo_tipo(p);
	abrir_arquivo(l);
	
	return 0;
}