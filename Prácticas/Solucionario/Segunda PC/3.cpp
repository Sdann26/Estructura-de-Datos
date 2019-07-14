#include <iostream>
#include <stdlib.h>

using namespace std;


/* Estructura para la lista doblemente enlazada */
typedef struct nodo {
   int valor;
   struct nodo *siguiente;
   struct nodo *anterior;
} tipoNodo;//Le damos un nombre

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void MostrarLista(Lista l);

int main() {
   
   int n;
   int x;
   int i=0;
   
   /* Nodos Auxiliares*/
   Lista lista = NULL;
   pNodo p;
   
   cout<< "Cuantos elementos insertaras: ";
   cin>> n;
   cout<<endl;

	while(i<n){
	
		cout<< "Insertar un elemento entero: "; cin>>x;
		Insertar(&lista, x);
		i++;
	}
	
   cout<<endl;

   MostrarLista(lista);
   
   cout<<endl;

   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nuevo, actual;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo)); /*Podemos usar new ()*/
   nuevo->valor = v;
   
   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo */
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual; 
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
      while(actual->siguiente && actual->siguiente->valor <= v) 
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;


	/*Imprime si la lista esta vacia*/
   if(!lista) cout <<"Lista vacía";

   nodo = lista;
   
      while(nodo->anterior) nodo = nodo->anterior;
      cout <<"Orden menor a mayor: ";
      
      /*Imprime cada valor de la lista primero imprimiendo el nodo y luego pasandole el valor de nodo siguiente al nodo y repitiendo hasta ser NULL*/
      while(nodo) {
         cout<< nodo->valor<<" ";
         nodo = nodo->siguiente;
      }
   
   cout <<endl;
}

