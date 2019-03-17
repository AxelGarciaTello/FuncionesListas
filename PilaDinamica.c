#include "PilaDinamica.h"

NODO *CrearNodo(NODO *enlace, TipoDato x){
	NODO *nuevo=(NODO *) malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->siguiente=enlace;
	return nuevo;
}

void insertarCabLSE(NODO **cab, TipoDato x){
	NODO *nuevo=CrearNodo(nuevo,x);
	nuevo->siguiente=*cab;
	*cab=nuevo;
}

void eliminarLSE(NODO **cab, TipoDato x){
	NODO *ant, *actual=*cab;
	int bandera=0;
	while (actual && bandera==0){
		bandera=(actual->dato==x);
		if(bandera==0){
			ant=actual;
			actual=actual->siguiente;
		}
		if(actual!=NULL){
			if(actual==*cab){
				*cab=actual->siguiente;
			}
			else{
				ant->siguiente=actual->siguiente;
			}
		free(actual);
		}
	}
}

void imprimirLSE(NODO *cab){
	if(cab!=NULL){
		imprimirLSE(cab->siguiente);
		printf("%d",cab->dato);
	}
}
