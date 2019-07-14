#include <iostream>
#include <stdlib.h>

using namespace std;

/* Estructura para la lista simplemente enlazada */
typedef struct nodo{

	struct nodo *siguiente;
	int valor;

};


/* Funciones con listas: */
void Insertar(nodo *&, int );
int sum (nodo *&);

int main (){

	int grado;
	int x;
	int i=0;
	int sum;
	
	nodo *lista = NULL; 	
	cout << "De que grado es tu polinomio: ";
	cin >> grado; 
	
	while (i<grado+1){
	
		cout<< "Insertar un elemento entero para el coeficiente: "; cin>>x;
		Insertar(lista, x);
		i ++;
	
	}	
	
	sum = sum (lista);
	
	cout<<endl;
	
   cout<<"La suma es "<<sum<<endl;

   return 0;

}

void Insertar (nodo *& lista ,int n){

	nodo *nuevo = new nodo();
	nuevo-> valor = n;
	
	nodo *aux1 = lista;
	nodo *aux2;
	
	if (lista == aux1){
		lista = nuevo;
	}
	else{
		aux2 -> siguiente = nuevo;
	}
	
	nuevo -> siguiente = aux1 ;
}

int sum(nodo *&lista){

	

}
