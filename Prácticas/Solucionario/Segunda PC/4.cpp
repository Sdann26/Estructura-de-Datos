#include <iostream>
#include <stdlib.h>

using namespace std;

/* Estructura para la lista simplemente enlazada */
typedef struct nodo{

	struct nodo *siguiente;
	int valor;

}tipoNodo;//Le damos un nombre a la estructura

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void MostrarLista(Lista l);

int main (){

	int grado;
	int x;
	int i=0;
	
	/* Nodos Auxiliares */
	Lista lista = NULL; 
	pNodo p;
	
	cout << "De que grado es tu polinomio: ";
	cin >> grado; 
	
	while (i<grado+1){
	
		cout<< "Insertar un elemento entero para el coeficiente: "; cin>>x;
		Insertar(&lista, x);
		i ++;
	
	}	
	
   cout<<endl;

   MostrarLista(lista);
   
   cout<<endl;

   return 0;

}

void insertar (int *& ,int ){

	

}
