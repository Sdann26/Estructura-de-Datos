#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
	
	int dato;
	Nodo *izq;
	Nodo *der;
	
};

Nodo *crearNodo(int);
void insertarArbol(Nodo *&, int); 
void mostrarArbol(Nodo *, int); // Imprime el arbol hechado
bool buscarArbol(Nodo* , int); // Algoritmo de busqueda binaria

int main(){
	
	Nodo *arbol = NULL;
	int n;
	int opc=0;
	int cont=0;
	bool busq; // Ve si un elemento esta o no
	
	do{
		
		cout<<"\t\tMENU:\n";
		
		cout << "\n1. Inserta el dato en el Arbol.";
		cout << "\n2. Imprimir el Arbol completo.";
		cout << "\n3. Busca un elemento en el Arbol.";
		cout << "\n4. Salir.";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					insertarArbol(arbol, n); 
					cout<<"\nSe agrego correctamente "<<n<<" al Arbol\n\n"; break;
			case 2: cout << "\nImprimiendo Arbol... \n";
					mostrarArbol(arbol, cont); break;
			case 3: cout << "\nQue elemento desea buscar: "; 
					cin >> n;
					busq = buscarArbol(arbol,n);
					if(busq == true){
						
						cout<<"\nSi se encuentra el elemento.\n"<<n<<endl;
						
					}
					
					else cout<<"\nNo existe este elemento en el Arbol.\n"<<endl;
					break;
			case 4: break;
			default: cout<<"\nNo inserto ninguna opcion\n"<<endl;
		}
		
	}while(opc != 4);

	
	
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
	
}

void mostrarArbol(Nodo *arbol, int contador){
	
	int i;
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
		
		mostrarArbol(arbol -> der, contador + 1);
		
		for (i=0; i<contador; i++){
			
			cout<<"   ";
			
		}
		
		cout<<arbol -> dato<<endl;
		
		mostrarArbol(arbol -> izq, contador + 1);
		
	}
	
}

bool buscarArbol(Nodo* arbol, int n){
	
	if (arbol == NULL){ // Si no esta el elemento me devuelve falso
		
		return false;
		
	}
	
	else if(arbol -> dato == n){ // Esta funcion comprueba si hay elemento
	
		return true;		
	
	}
	
	else{
		
		if(arbol -> dato < n){ // Si es que no esta en este nodo lo buscara por el lado derecho
			
			buscarArbol(arbol -> der, n);
			
		}
		
		else{ // Si es que no esta en este nodo lo buscara por el lado izquierdo
			
			buscarArbol(arbol -> izq, n);
			
		}
		
	}
	
}
