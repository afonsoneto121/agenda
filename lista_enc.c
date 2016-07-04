#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "tipo.h"

struct agenda
{
    char *primeiro_nome;
    char **nome_completo;
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
        if(strcmp(atual->agenda->numero_telefone , c) == 0) return anterior;
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
        printf("%s ",p->agenda->primeiro_nome);
    }
}

Agenda * criar_agenda(char **nome_completo,char *numero_telefone, char *email, char *tipo)
{
    Agenda *nova = (Agenda*) malloc(sizeof(Agenda));
    nova->nome_completo = nome_completo;
    nova->numero_telefone =numero_telefone;
    nova->email = email;
    nova->tipo = tipo;
    nova->primeiro_nome = nome_completo[0];
    return nova;
}


void abrir_arquivo()
{
    FILE *p = fopen("banco","a");
    fprintf(p, "ssfs");
    fclose(p);
}

void ler_arquivo()
{
    FILE *p = fopen("banco","r");
    char *c;
    while((c = fgetc(p)) != EOF)
    {
        printf("%c ", c);
    }
    fclose(p);

}