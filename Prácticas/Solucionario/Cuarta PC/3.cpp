#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
	
	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *raiz; // Raiz o nodo padre
	
};

Nodo *crearNodo(int, Nodo *);
void insertarArbol(Nodo *&, int, Nodo *); 
void mostrarArbol(Nodo *, int); // Imprime el arbol hechado
bool semejanzaArboles(Nodo *, Nodo* );


int main(){
	
	Nodo *arbol1 = NULL;
	Nodo *arbol2 = NULL;
	int n;
	int arbolito;
	int opc=0;
	int cont=0;
	bool semejanza; // Ve si el arbol es semejante o no
	
	do{
		
		cout<<"\t\tMENU:\n";
		
		cout << "\n1. Insertar datos en algun Arbol.";
		cout << "\n2. Imprimir el Arbol completo.";
		cout << "\n3. Comprobar si son semejantes.";
		cout << "\n4. Salir.";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					cout << "\nA que Arbol deseas agregar el valor: ";
					cin >> arbolito;
					if (arbolito == 1){
						insertarArbol(arbol1, n, NULL); 
					}
					if (arbolito == 2){
						insertarArbol(arbol2, n, NULL);
					}
					cout << "\nSe agrego correctamente "<<n<<" al Arbol "<<arbolito<<" \n\n"; 
					break;
			case 2: cout << "\nQue Arbol deseas imprimir: ";
					cin >> arbolito;
					if (arbolito == 1){
						insertarArbol(arbol1, n, NULL);
						cout << "\nImprimiendo Arbol... \n"<<endl;
						mostrarArbol(arbol1, cont);  
					}
					if (arbolito == 2){
						insertarArbol(arbol2, n, NULL);
						cout << "\nImprimiendo Arbol... \n"<<endl;
						mostrarArbol(arbol2, cont); 
					}
					break;
			case 3: semejanza=semejanzaArboles(arbol1,arbol2);
					if(semejanza == true){
						cout << "Son arboles semejantes\n" << endl;
					}
					else{
					 	cout << "NO Son arboles semejantes\n" << endl;
					}
					break;
			case 4: break;
			default: cout<<"\nNo inserto ninguna opcion.\n"<<endl;
		}
		
	}while(opc != 4);
	
	return 0;	
	
}

// Funcion para crear Nodos
Nodo *crearNodo(int n, Nodo *raiz){
	
	Nodo *nuevo_nodo = new Nodo(); 
	
	nuevo_nodo -> dato = n;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> der = NULL;
	nuevo_nodo -> raiz = raiz;
	
	return nuevo_nodo;
}

void insertarArbol(Nodo *&arbol, int n, Nodo *raiz){
	
	if (arbol == NULL){ // Caso si el arbol esta vacio
		
		Nodo *nuevo_nodo = crearNodo(n, raiz);
		arbol = nuevo_nodo;
		
	}
	
	else { //Caso si el arbol no esta vacio
		
		if (n < arbol -> dato){
			
			insertarArbol(arbol -> izq, n, arbol); // Inserta por el hijo de la izquierda
			
		}
		
		else{
			
			insertarArbol(arbol -> der, n, arbol); // Inserta por el hijo de la derecha
			
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

bool semejanzaArboles(Nodo *arbol1,Nodo* arbol2){

	if (arbol1 == NULL && arbol2 == NULL){
		
		return true;
	
	}
	
	else{
	
		if (arbol1 != NULL && arbol2 != NULL){
		
			if(semejanzaArboles(arbol1->izq,arbol2->izq) && semejanzaArboles(arbol1->der,arbol2->der)){
			
				return true;
			
			}
			
			else{
			
				return false;
			
			}
		
		}
	
		return false;
	
	}

}
