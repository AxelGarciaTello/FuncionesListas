/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Cabeceras para las funciones de listas
 * 
 * Fecha: 17 de marzo de 2019
*/

#include "PilaDinamica.h"

//Función para la creación de un nodo
NODO *CrearNodo(NODO *enlace, TipoDato x){
	NODO *nuevo=(NODO *) malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->siguiente=enlace;
	return nuevo;
}

//Función para la insertar un valor en un nodo
void insertarCabLSE(NODO **cab, TipoDato x){
	NODO *nuevo=CrearNodo(nuevo,x);
	nuevo->siguiente=*cab;
	*cab=nuevo;
}

//Función para eliminar una lista
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

//Función para imprimir una lista
void imprimirLSE(NODO *cab){
	if(cab!=NULL){
		imprimirLSE(cab->siguiente);
		printf("%d",cab->dato);
	}
}
