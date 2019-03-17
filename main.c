#include "PilaDinamica.h"

NODO *suma(NODO *n1, NODO *n2){
	int numero1, numero2, resultado, sobrante=0;
	NODO *salida=NULL;
	NODO *SumaCompleta=NULL;
	while(n1!=NULL && n2!=NULL){
		numero1=n1->dato;
		numero2=n2->dato;
		resultado=numero1+numero2+sobrante;
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);
		n1=n1->siguiente;
		n2=n2->siguiente;
	}
	while(n1!=NULL){
		numero1=n1->dato;
		resultado=numero1+sobrante;
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);
		n1=n1->siguiente;
	}
	while(n2!=NULL){
		numero2=n2->dato;
		resultado=numero2+sobrante;
		sobrante=0;
		while(resultado>=10){
			resultado-=10;
			sobrante++;
		}
		insertarCabLSE(&salida, resultado);
		n2=n2->siguiente;
	}
	if(sobrante!=0){
		insertarCabLSE(&salida, sobrante);
	}
	while(salida!=NULL){
		resultado=salida->dato;
		insertarCabLSE(&SumaCompleta, resultado);
		salida=salida->siguiente;
	}
	return SumaCompleta;
}

NODO *multiplicacion(NODO *n1, NODO *n2){
	int numero1, numero2, resultado, sobrante=0, posicion=0,
	copiaposicion;
	NODO *copia=NULL;
	NODO *fila=NULL;
	NODO *voltero=NULL;
	NODO *MultiplicacionCompleta=NULL;
	while(n2!=NULL){
		numero2=n2->dato;
		copia=n1;
		fila=NULL;
		copiaposicion=posicion;
		while(copiaposicion>0){
			insertarCabLSE(&fila, 0);
			copiaposicion--;
		}
		posicion++;
		while(copia!=NULL){
			numero1=copia->dato;
			resultado=(numero1*numero2)+sobrante;
			sobrante=0;
			while(resultado>=10){
				resultado-=10;
				sobrante++;
			}
			insertarCabLSE(&fila, resultado);
			copia=copia->siguiente;
		}
		if(sobrante!=0){
			insertarCabLSE(&fila, sobrante);
		}
		sobrante=0;
		voltero=NULL;
		while(fila!=NULL){
			numero1=fila->dato;
			insertarCabLSE(&voltero, numero1);
			fila=fila->siguiente;
		}
		MultiplicacionCompleta=suma(MultiplicacionCompleta, voltero);
		n2=n2->siguiente;
	}
	return MultiplicacionCompleta;
}
	
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

int main(void){
	ingresarDatos();
	return 0;
}
