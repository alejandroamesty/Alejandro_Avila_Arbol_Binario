/* Escribir un programa en lenguaje C que permita definir un arbol binario. El mismo debe contener:

	- Definicion de la estructura de un arbol binario.
	- Funcion para crear un Nodo.
	- Funcion para agregar un valor.
	- Funcion para recorrer el arbol. */

#include<stdio.h>
#include<stdlib.h>

// Definicion de la estructura de un arbol binario:

struct nodo{
	
	struct nodo *padre;
	struct nodo *izquierdo;
	struct nodo *derecho;
	int valor;
	
};

// Prototipos:

struct nodo *crear_nodo(struct nodo *padre, int valor);
void agregar_valor(struct nodo * arbol, int valor);
void preOrden(nodo *arbol);
	
int main(){
	
	struct nodo *arbol;
	arbol = crear_nodo(NULL,40);
	agregar_valor(arbol,10);
	agregar_valor(arbol,50);
	
}

// Funcion para crear un Nodo:

struct nodo *crear_nodo(struct nodo *padre, int valor){
	
	struct nodo *n = (struct nodo*) calloc(sizeof(struct nodo), 1);
	n -> padre = padre;
	n -> valor = valor;
	return n;
	
}

// Funcion para agregar un valor:

void agregar_valor(struct nodo *arbol, int valor){

	struct nodo *temp, *pivote;
	int derecho = 0;
	if(arbol){
		temp = arbol;
		while(temp != NULL){
			pivote = temp;
			if(valor > temp -> valor){
				temp = temp -> derecho;
				derecho = 1;
			}
			else{
				temp = temp -> izquierdo;
				derecho = 0;
			}
		}
		temp = crear_nodo(pivote, valor);
		if(derecho){
			printf("Insertando %i del lado derecho de %i\n", valor, pivote -> valor);
			pivote -> derecho = temp;
		}
		else{
			printf("Insertando %i del lado izquierdo de %i\n", valor, pivote -> valor);
			pivote -> izquierdo = temp;
		}
	}
	else{
		printf("Error, no esta inicializado el arbol");
	}
}

// Funcion para recorrer el arbol:

void preOrden(nodo *arbol){

	if(arbol == NULL){
		return;
	}
	else{
		printf(" - ", arbol -> valor);
		preOrden(arbol -> izquierdo);
		preOrden(arbol -> derecho);
	}
}

/* Existen diferentes formas para recorrer un arbol, esta el recorrido en anchura y
el recorrido en profundidad, que a su vez se divide en PreOrden, InOrden y PostOrden. */
