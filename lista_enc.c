#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "tipo.h"

struct agenda
{
    char *primeiro_nome;
    char *nome_completo;
    char *numero_telefone;
    char *email;
    char *tipo;
};

typedef struct no{
   struct agenda* agenda;
   struct no* proximo;
} No;

struct listaE{
  No* inicio;
};


    
/*Cria uma lista vazia*/
ListaE* le_criarLista(){
    ListaE* lista = (ListaE*)malloc(sizeof(ListaE));
    lista->inicio = NULL;
    return lista;
}

int le_inserir(ListaE* lista, Agenda *c)
{
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL) return -1;
    if(le_buscar(lista,c->numero_telefone) == NULL)
    {
        novoNo->agenda = c;
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;    
        return 1;
    }
    return 0;
}


No* le_buscar(ListaE* lista, char *c)
{
    No* atual = lista->inicio;
    No* anterior = NULL;
    while(atual != NULL){
        if(strcmp(atual->agenda->numero_telefone , c) == 0)
        {
            printf("%s, ",atual->agenda->primeiro_nome);
            printf("%s, ",atual->agenda->nome_completo);
            printf("%s, ",atual->agenda->numero_telefone);
            printf("%s, ",atual->agenda->email);
            printf("%s, ",atual->agenda->tipo);
            printf("\n");
            return anterior;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover(ListaE* lista, char * c){
     No* primeiro = lista->inicio;
     if(strcmp(primeiro->agenda->numero_telefone , c) == 0){
        lista->inicio = primeiro->proximo;
        free(primeiro);
        return;
     }else{
        No* anterior = le_buscar(lista, c);
        if(anterior != NULL){
            No* atual = anterior->proximo;
            anterior->proximo = atual->proximo;
            free(atual);
         }
     }
}
void le_imprimi(ListaE *l)
{
    No* p = l->inicio;
    for (; p != NULL; p = p->proximo)
    {
        printf("%s, ",p->agenda->primeiro_nome);
        printf("%s, ",p->agenda->nome_completo);
        printf("%s, ",p->agenda->numero_telefone);
        printf("%s, ",p->agenda->email);
        printf("%s, ",p->agenda->tipo);
        printf("\n");

    }


    printf("\n");
}

Agenda * criar_agenda(char *nome_completo,char *numero_telefone, char *email, char *tipo)
{
    int tam = strlen(nome_completo);
    char *c = (char*) malloc(tam*sizeof(char));
    int i;
    Agenda *nova = (Agenda*) malloc(sizeof(Agenda));
    nova->nome_completo = nome_completo;
    nova->numero_telefone =numero_telefone;
    nova->email = email;
    nova->tipo = tipo;
    for (i = 0; i < tam; i++)
    {
        c[i] = nome_completo[i];
        if(nome_completo[i] == ' ')
        {
            break;
        }
    }
    c[i] = '\0';
    nova->primeiro_nome = c;
    return nova;
}


void abrir_arquivo(ListaE *l)
{
    FILE *banco = fopen("banco","w");
    No* p = l->inicio;
    int i;
    for (; p != NULL; p = p->proximo)
    {

        int tam = strlen(p->agenda->nome_completo);        
        char *d = (char*) malloc(tam*sizeof(char));
        
        for (i = 0; i < tam; i++)
        {
            d[i] = p->agenda->nome_completo[i];
        }

        formatar(d);
        d[i] = '\0';
        fprintf(banco,d);
        fprintf(banco," ");
        fprintf(banco,p->agenda->numero_telefone);
        fprintf(banco," ");
        fprintf(banco,p->agenda->email);
        fprintf(banco," ");
        fprintf(banco,p->agenda->tipo);
        fprintf(banco,"\n");
    }   
    fclose(banco);
}

void ler_arquivo(ListaE *l)
{

    FILE *p = fopen("banco","r");
    int cont = 1;
    int num = 0;
    char ch;    
    while( (ch=fgetc(p))!= EOF )
            if(ch == '\n')
              num++;

    fseek(p, 0,SEEK_SET);
    while(cont <= num)
    {
        Agenda *novo;
        char *nome_completo = (char*) malloc(100 * sizeof(char));
        char *numero_telefone = (char*) malloc(10 * sizeof(char));
        char *email = (char*) malloc(100 * sizeof(char));
        char *tipo = (char*) malloc(50 * sizeof(char));
        fscanf(p,"%s %s %s %s\n", nome_completo, numero_telefone,email,tipo);
        desformatar(nome_completo);
        novo = criar_agenda(nome_completo,numero_telefone,email,tipo);
        le_inserir(l,novo);
        cont++;

    }
    
    fclose(p);

}

void formatar(char *c)
{
    int tam = strlen(c), i;
    for (i = 0; i < tam; i++)
    {
        if(c[i] == '-') 
        {
            c[i] = '&';
        }
    }
}

void desformatar(char *c)
{
    int tam = strlen(c), i;
    for (i = 0; i < tam; i++)
    {
        if(c[i] == '&') c[i] = '-';
    }
}