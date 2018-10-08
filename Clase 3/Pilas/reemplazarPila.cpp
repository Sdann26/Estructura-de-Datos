// Reemplaza el valor viejo en la pila por un valor nuevo

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{

       int dato;
       Nodo *siguiente;

};

int n;

void agregarPila (Nodo *& ,int );
void quitarPila (Nodo *&);
void imprimirPila (Nodo *,int );
void quitarPila (Nodo *&);
void reemplazarPila (Nodo *&, int ,int );

int main(){

    Nodo *pila=NULL;
    int dato;
    int i;
    int viejo;
    int nuevo;

    cout<<"Cuantos elementos quieres en la pila: ";
    cin>>n;


    for(i=0; i<n; i++){

    	cout<<"Inserta elemento a la pila: ";
    	cin>>dato;

    	agregarPila (pila, dato);

	}

    cout<<endl;

    cout<<"Que valor se desea reemplazar: ";
    cin>>viejo;
    cout<<"Que valor desea darle: ";
    cin>>nuevo;

    cout<<endl;

    // Funcion que reemplaza los viejos valores por los nuevos

    reemplazarPila(pila,viejo,nuevo);

	// Imprime valores de la Pila
	imprimirPila(pila,n);

    system("PAUSE");
    return 0;

}

// Agrega nodos a la Pila
void agregarPila (Nodo *&pila ,int n){

     Nodo *nuevo_nodo = new Nodo(); // Reservamos memoria para un nuevo nodo (Auxiliar)

     nuevo_nodo->dato = n; // Le asigna un valor al nuevo_nodo
     nuevo_nodo->siguiente = pila; // Al Nodo siguiente le asigna la direccion de pila que apunta a NULL
     pila = nuevo_nodo; // Nuestra Pila principal se vuelve el nuevo_nodo

	 cout<<"Se inserto el valor "<<nuevo_nodo->dato<<" correctamente"<<endl;

}

// Quita el ultimo elemento de la Pila
void quitarPila (Nodo *&pila){


    // Verificamos si la Pila esta vacia
    if (pila != NULL){

        Nodo *nuevo_nodo = pila;
        pila = nuevo_nodo->siguiente;
        cout<<"Eliminamos el valor: "<<nuevo_nodo->dato<<endl;

        delete nuevo_nodo;

    }

    else{

        cout<<"La Pila esta vacia";

    }
}


// Imprime lo que hay en la cola
void imprimirPila (Nodo *pila, int n){

	int i;

	for(i=0; i<n; i++){

        Nodo *nuevo_nodo = pila;
        pila = nuevo_nodo->siguiente;
        cout<<nuevo_nodo->dato<<" -> ";

	}

	cout<<"NULL";

}

void reemplazarPila (Nodo *&pila, int viejo, int nuevo ){

	int i;

	Nodo *aux = pila;

	for(i=0; i<n; i++){

 		if (viejo == aux->dato){

 			aux->dato = nuevo;

		}

		aux = aux->siguiente;

	}

}
