// Quita un elemento de la Pila 

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
       
       int dato;
       Nodo *siguiente;
       
};

void agregarPila (Nodo *& ,int );
void quitarPila (Nodo *&);

int main(){
    
    Nodo *pila=NULL;
    int n;
    
    cout<<"Inserta un numero a la pila: ";
    cin>>n;
    
    agregarPila (pila, n);
    
    cout<<"Inserta un numero a la pila: ";
    cin>>n;
    
    cout<<endl;
    
    agregarPila (pila, n);
    
    quitarPila (pila);
    quitarPila (pila);
    quitarPila (pila);
    
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
