#include <stdio.h>
#include <stdlib.h>

typedef int TipoDato;

typedef struct nodo{
	TipoDato dato;
	struct nodo *siguiente;
} NODO;

NODO *CrearNodo(NODO *, TipoDato);
void insertarCabLSE(NODO **, TipoDato);
void eliminarLSE(NODO **, TipoDato);
void imprimirLSE(NODO *);
