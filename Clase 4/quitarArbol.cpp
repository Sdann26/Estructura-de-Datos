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
bool buscarArbol(Nodo* , int); // Algoritmo de busqueda binaria
void preOrden(Nodo* ); 
void inOrden(Nodo* ); 
void postOrden(Nodo* ); 
// Estas dos funciones trabajaran juntas
void eliminarArbol(Nodo *&, int);
void eliminarNodo(Nodo *&);

Nodo *minimo(Nodo *);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);


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
		cout << "\n4. Realizar Recorrido Pre-Orden:";
		cout << "\n5. Realizar Recorrido In-Orden:";
		cout << "\n6. Realizar Recorrido Post-Orden:";
		cout << "\n7. Eliminar un nodo del arbol:";
		cout << "\n8. Salir.";
		
		cout << "\n\nElije una opcion: ";
		cin>>opc;
		
		switch(opc){
			
			case 1: cout << "\nQue valor desea agregar al Arbol: ";
					cin >> n;
					insertarArbol(arbol, n, NULL); 
					cout << "\nSe agrego correctamente "<<n<<" al Arbol\n\n"; break;
			case 2: cout << "\nImprimiendo Arbol... \n"<<endl;
					mostrarArbol(arbol, cont); break;
			case 3: cout << "\nQue elemento desea buscar: "; 
					cin >> n;
					busq = buscarArbol(arbol,n);
					if(busq == true){
						
						cout<<"\nSi se encuentra el elemento "<<n<<endl<<endl;
						
					}
					
					else cout<<"\nNo existe este elemento en el Arbol.\n"<<endl;
					break;
			case 4: cout << "\nRecorrido: ";
					preOrden(arbol); cout<<"FIN\n\n"; break;
			case 5: cout << "\nRecorrido: ";
					inOrden(arbol); cout<<"FIN\n\n"; break;
			case 6: cout << "\nRecorrido: ";
					postOrden(arbol); cout<<"FIN\n\n"; break;
			case 7: cout << "\nQue elemento desea eliminar: ";
					cin >> n;
					eliminarArbol(arbol, n);
					cout << endl; break;
			case 8: break;
			default: cout<<"\nNo inserto ninguna opcion.\n"<<endl;
		}
		
	}while(opc != 8);
	
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

void preOrden(Nodo* arbol){ // Imprime la raiz luego al sub-arbol izquierdo al final el derecho
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
		
		cout << arbol->dato << " -> ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
		
	}
	
}

void inOrden(Nodo* arbol){ // Imprime el sub-arbol izquierdo luego la raiz y al final el derecho
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
		
		inOrden(arbol->izq);
		cout << arbol->dato << " -> ";
		inOrden(arbol->der);
		
	}
	
}

void postOrden(Nodo* arbol){ // LLena primero los nodos izquierda del sub arbol izquierdo luego el derecho y por el ultimo la raiz
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
		
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->dato << " -> ";
		
	}
	
}

// Funcion que encuentra el nodo que deseamos eliminar
void eliminarArbol(Nodo *&arbol, int n){
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else if (n < arbol->dato){
		
		eliminarArbol(arbol->izq, n);
		
	}
	
	else if (n > arbol->dato){
		
		eliminarArbol(arbol->der, n);
		
	}
	
	else{
		
		eliminarNodo(arbol);
		
	}
	
}

// Funcion para deterinar el nodo mas izquierdo posible 
Nodo *minimo(Nodo *arbol){
	
	if (arbol == NULL){
		
		return NULL; // Retorna NULL si esta vacio el arbol
		
	}
	
	if (arbol->izq){
		
		return minimo(arbol->izq); // Retorna al nodo mas izquierdo posible
		
	}
	
	else{
		
		return arbol; // Retorna al nodo actual
		
	}
	
}

// Funcion para reemplazar
void reemplazar (Nodo *arbol, Nodo *nuevoNodo){
	
	if (arbol->raiz){
		
		//arbol-><padre hay que asignarle un nuevo hijo
		if(arbol->dato == arbol->raiz->izq->dato){
			
			arbol->raiz->izq = nuevoNodo;
			
		}

		else if(arbol->dato == arbol->raiz->der->dato){
			
			arbol->raiz->der = nuevoNodo;
			
		}
				
	}
	
	if (nuevoNodo){
		
		// Procedemos a asignarle su nuevo padre
		nuevoNodo->raiz = arbol->raiz;
		
	}
}

// Destruye el nodo y su espacio de memoria
void destruirNodo(Nodo *nodo){
	
	nodo->der = NULL;
	nodo->izq = NULL;
	delete nodo;
	
}


// Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *&nodoEliminar){
	
	if (nodoEliminar->der && nodoEliminar->izq){ // Verifica si tiene nodo izquierdo y derecho
		
		Nodo *menor = minimo (nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
		
	}
	
	else if (nodoEliminar->izq){ // Si tiene hijo izquierdo
		
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
		
	}
	
	else if (nodoEliminar->der){ // Si tiene hijo derecho
		
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
		
	}
	
	else{ // Si un nodo no tiene hijos
		
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
		
	}
	
}
