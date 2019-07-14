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
Nodo *buscarArbol(Nodo* , int, int); // Algoritmo de busqueda binaria


int main(){
	
	Nodo *arbol = NULL;
	int n;
	int m;
	int opc=0;
	int cont=0;
	Nodo *busq; // Encuentra el padre comun mas joven
	
	do{
		
		cout<<"\t\tMENU:\n";
		
		cout << "\n1. Inserta el dato en el Arbol.";
		cout << "\n2. Imprimir el Arbol completo.";
		cout << "\n3. Busca un al padre comun mas joven.";
		cout << "\n4. Salir.";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					insertarArbol(arbol, n, NULL); 
					cout << "\nSe agrego correctamente "<<n<<" al Arbol\n\n"; break;
			case 2: cout << "\nImprimiendo Arbol... \n"<<endl;
					mostrarArbol(arbol, cont); break;
			case 3: cout << "\nCual es el primer nodo: ";	cin >> n;
					cout << "\nCual es el segundo nodo: ";	cin >> m;
					busq = buscarArbol(arbol,n,m);
					cout << "\nEl padre comun mas joven es: "<<busq->dato<<endl;	
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

Nodo *buscarArbol(Nodo* arbol, int n, int m){
	
if(!arbol) {

    return NULL;
            
    }
    if(arbol->dato == n || arbol->dato == m) {
        
        return arbol;
        
        }
        
    else{
    
        if((n > arbol->dato && m < arbol->dato) || (n < arbol->dato && m > arbol->dato)){
            return arbol;
        }

        if(n < arbol->dato && m < arbol->dato){
            arbol = buscarArbol(arbol->izq, n, m);
        }

        if(n > arbol->dato && m > arbol->dato){
            arbol = buscarArbol(arbol->der, n, m);
        }
    }
    
return arbol;
	
}



