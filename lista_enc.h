#ifndef LISTA_H
#define LISTA_H

typedef struct agenda Agenda;

typedef struct listaE ListaE;

typedef struct no No;

ListaE* le_criarLista();
int le_inserir(ListaE* lista, Agenda *c);
No* le_buscar(ListaE* lista, char *c);
void remover(ListaE* lista, char *c);
void le_imprimi(ListaE *l);
Agenda * criar_agenda(char **nome_completo,char *numero_telefone, char *email, char *tipo);


#endif