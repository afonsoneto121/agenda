#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "tipo.h"

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

int main(int argc, char const *argv[])
{
	char *nome_completo[] = {"Afonso", "Neto"};
	char *nome_completo_2[] = {"Teste", "eewew"};
	char *numero_telefone = "88996396668";
	char *email = "teste@teste.com";
	char *tipo = "Trabalho";

	//int op = inicio();

	Agenda *agenda = criar_agenda(nome_completo,numero_telefone,email,tipo);
	Agenda *agenda_2 = criar_agenda(nome_completo_2,numero_telefone,email,tipo);
	ListaE *l = le_criarLista();
	int c = le_inserir(l,agenda);
	int d = le_inserir(l,agenda_2);
	le_imprimi(l);

	return 0;
}