// Escriba una funcion que tome como entrada un arbol binario de busqueda, arbol, y dos llaves k1 y k2 , tal que, k1 < llave(x) < k2 , y visualice todos los elementos x

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
void llaves(Nodo*, int, int); // Te da las llaves que hay entre la llave k1 y k2

int main(){
	
	Nodo *arbol = NULL;
	int n;
	int opc=0;
	int cont = 0;
	int k1,k2;
	bool busq; // Ve si un elemento esta o no
	
	do{
		
		cout<<"\t\tMENU:\n";
		
		cout << "\n1. Inserta el dato en el Arbol.";
		cout << "\n2. Imprimir el Arbol completo.";
		cout << "\n3. Busca numeros en un intervalo.";
		cout << "\n4. Salir.";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					insertarArbol(arbol, n); 
					cout << "\nSe agrego correctamente "<<n<<" al Arbol\n\n"; break;
			case 2: cout << "\nImprimiendo Arbol... \n"<<endl;
					mostrarArbol(arbol, cont); break;
			case 3: cout << "\nCual es la primera llave: "; cin >> k1;
					cout << "\nCual es la segunda llave: "; cin >> k2;
					llaves(arbol, k1, k2);
					cout << "FIN\n"<<endl;	break;
			case 4: break;
			default: cout<<"\nNo inserto ninguna opcion.\n"<<endl;
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

void llaves(Nodo* arbol,int k1,int k2){ // Imprime un intervalo teniendo el limite inferior k1 y el superior k2 (función de recorrido in-Orden pero con limites)
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
				
		llaves(arbol->izq,k1,k2);
		
		if (k1<=arbol->dato && arbol->dato<=k2 ){ // Solo imprime los valores que cumplen la condicion los demás no los imprime
			
			cout << arbol->dato << " -> ";
		
		}
		
		llaves(arbol->der,k1,k2);
		
	}
	
}
