#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
	
	int dato;
	Nodo *izq;
	Nodo *der;
	
};

Nodo *crearNodo(int);
void insertarArbol(Nodo *&, int ); 

int main(){
	
	Nodo *arbol = NULL;
	int n;
	int opc=0;
	
	do{
		
		cout<<"\t\tMENU:\n";
		
		cout << "\n1. Inserta el dato en el Arbol";
		cout << "\n2. Salir";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					insertarArbol(arbol, n);break;
			case 2: break;
			default: cout<<"\nNo inserto ninguna opcion\n"<<endl;
		}
		
	}while(opc != 2);

	
	
	return 0;	
	
}

// Funcion para crear Nodos
Nodo *crearNodo(int n){
	
	Nodo *nuevo_nodo = new Nodo(); 
	
	nuevo_nodo -> dato = n;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> der = NULL;
	
	return nuevo_nodo;
}

void insertarArbol(Nodo *&arbol, int n){
	
	if (arbol == NULL){ // Caso si el arbol esta vacio
		
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
		
	}
	
	else { //Caso si el arbol no esta vacio
		
		if (n < arbol -> dato){
			
			insertarArbol(arbol -> izq, n); // Inserta por el hijo de la izquierda
			
		}
		
		else{
			
			insertarArbol(arbol -> der, n); // Inserta por el hijo de la derecha
			
		}
		
	}
	
	cout<<"\nSe agrego correctamente "<<n<<" al Arbol\n\n";
	
}
