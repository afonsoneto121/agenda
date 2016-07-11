#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"

struct tipo
{
	int tam;
	char **nome;
};

Tipo *tipo_criar()
{
	Tipo* novo = (Tipo*) malloc(sizeof(Tipo));
	novo->tam = 0;
    char **c = (char*) malloc(20 * sizeof(char));
    int i;
    for (i = 0; i < 20; i++)
    {
        c[i] = (char*) malloc(20 * sizeof(char));
    }
    novo->nome = c;
	return novo;
}

void tipo_novo(Tipo *tipo, char *c)
{
	tipo->nome[tipo->tam++] = c;
}

void imprimir_tipo(Tipo *tipo)
{
	int i;
	for (i = 0; i < tipo->tam; i++)
	{
		printf("%s\n", tipo->nome[i]);
	}
}


void abrir_arquivo_tipo(Tipo *tipo)
{
    FILE *banco = fopen("tipo","w");
    
    int i;
    for (i=0; i < tipo->tam; i++)
    {
    	fprintf(banco,"%s", tipo->nome[i]);
        fprintf(banco,"\n");
    }   
    fclose(banco);
}

void ler_arquivo_tipo(Tipo *t)
{

    FILE *p = fopen("tipo","r");
    int cont = 0;
    int num = 0;
    char ch;
    
    while( (ch=fgetc(p))!= EOF )
            if(ch == '\n')
              num++;

    fseek(p, 0,SEEK_SET);
    while(cont <= num)
    {
        char *info = (char*) malloc(20 * sizeof(char));    
        //char info[20];
        //fgets(info, sizeof(info), p);
        fscanf(p,"%s", info);
        t->nome[cont] = info;
        t->tam++;
        cont++;

    }
    
    
    
    fclose(p);

}