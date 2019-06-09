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

//Funcón para la realización se sumas con números de una lista
NODO *suma(NODO *n1, NODO *n2){
	int numero1, numero2, resultado, sobrante=0;
	NODO *salida=NULL;
	NODO *SumaCompleta=NULL;
	//Mientras las listas no esten vacias
	while(n1!=NULL && n2!=NULL){
		//Sumar los numeros de las listas
		numero1=n1->dato;
		numero2=n2->dato;
		resultado=numero1+numero2+sobrante;
		//Separar las decenas de los valores
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);//Guardamos el resultado
		//Actualizamos los datos
		n1=n1->siguiente;
		n2=n2->siguiente;
	}
	//Si la segunda lista esta vacia pero la primera no, entonces...
	while(n1!=NULL){
		numero1=n1->dato;
		resultado=numero1+sobrante;
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);/*Guardar los valores en el
											 resultado*/
		n1=n1->siguiente;
	}
	//Si la primer lista esta vacia pero la segunda no, entonces...
	while(n2!=NULL){
		numero2=n2->dato;
		resultado=numero2+sobrante;
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);/*Guardar los valores en el
											 resultado*/
		n2=n2->siguiente;
	}
	//Si hay un sobrante, guardarlo en el resultado
	if(sobrante!=0){
		insertarCabLSE(&salida, sobrante);
	}
	//Volterar el resultado
	while(salida!=NULL){
		resultado=salida->dato;
		insertarCabLSE(&SumaCompleta, resultado);
		salida=salida->siguiente;
	}
	return SumaCompleta;
}

//Función para multiplicar números grandes
NODO *multiplicacion(NODO *n1, NODO *n2){
	int numero1, numero2, resultado, sobrante=0, posicion=0,
	copiaposicion;
	NODO *copia=NULL;
	NODO *fila=NULL;
	NODO *voltero=NULL;
	NODO *MultiplicacionCompleta=NULL;
	//Mientras la segunda lista no este vacia
	while(n2!=NULL){
		numero2=n2->dato;
		copia=n1;
		fila=NULL;
		//Dependiendo de la posición del segundo número, agregar 0
		copiaposicion=posicion;
		while(copiaposicion>0){
			insertarCabLSE(&fila, 0);
			copiaposicion--;
		}
		posicion++;
		//Mientras la primer lista no se encuentre vacia
		while(copia!=NULL){
			numero1=copia->dato;
			resultado=(numero1*numero2)+sobrante; /*Multiplicamos los
													números de las
													listas*/
			//Separamos las decenas de los valores
			sobrante=0;
			while(resultado>=10){
				resultado-=10;
				sobrante++;
			}
			//Guardamos el resultado y actualizamos los datos
			insertarCabLSE(&fila, resultado);
			copia=copia->siguiente;
		}
		//Si hay un sobrante lo agregamos a nuestro resultado
		if(sobrante!=0){
			insertarCabLSE(&fila, sobrante);
		}
		sobrante=0;
		voltero=NULL;
		//Volteramos los resultados
		while(fila!=NULL){
			numero1=fila->dato;
			insertarCabLSE(&voltero, numero1);
			fila=fila->siguiente;
		}
		//Sumamos con los otros resultados generados
		MultiplicacionCompleta=suma(MultiplicacionCompleta, voltero);
		n2=n2->siguiente; //Actualizamos los datos
	}
	return MultiplicacionCompleta;
}

//Función para ingresar los datos
void ingresarDatos(void){
	char cn1, cn2;
	NODO *n1=NULL;
	NODO *n2=NULL;
	NODO *salida=NULL;
	int opcion;
	printf("Ingrese su primer numero:\n");
	scanf("%c",&cn1);
	while(cn1!='\n'){
		insertarCabLSE(&n1, (cn1-'0'));
		scanf("%c",&cn1);
	}
	printf("Ingrese su segundo numero:\n");
	scanf("%c",&cn2);
	while(cn2!='\n'){
		insertarCabLSE(&n2, (cn2-'0'));
		scanf("%c",&cn2);
	}
	printf("¿Que accion desera realizar?:\n");
	printf("\t1.Sumar\n");
	printf("\t2.Multiplicar\n");
	scanf("%d",&opcion);
	switch(opcion){
		case 1: salida=suma(n1,n2);
				imprimirLSE(salida);
				printf("\n");
		break;
		case 2: salida=multiplicacion(n1, n2);
				imprimirLSE(salida);
				printf("\n");
		break;
		default: printf("Opcion incorrecta\n");
		break;
	}
}

//Función principal main para ejecutar el programa
int main(void){
	ingresarDatos();
	return 0;
}
