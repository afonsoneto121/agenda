#ifndef TIPO_H
#define TIPO_H

typedef struct tipo Tipo;

Tipo *tipo_criar();

void tipo_novo(Tipo *tipo, char *c);

void imprimir_tipo(Tipo *tipo);

void abrir_arquivo_tipo(Tipo *tipo);

void ler_arquivo_tipo(Tipo *t);

#endif