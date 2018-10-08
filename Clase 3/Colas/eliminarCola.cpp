#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *siguiente;
	
};

void insertarCola(Nodo *&, Nodo*&, int);
void quitar_pCola (Nodo *&, Nodo*&);
void eliminarCola(Nodo *&, Nodo *&);
void imprimirCola(Nodo *);

int main(){
	
	int n;
	int opc=0;
	
	Nodo *Frente = NULL;
	Nodo *Fin = NULL;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar Nodo en Cola"<<endl;
		cout<<"2. Elimina el primer nodo de la Cola"<<endl;
		cout<<"3. Eliminar toda la Cola"<<endl;
		cout<<"4. Imprimir cola completa"<<endl;
		cout<<"5. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					insertarCola(Frente, Fin, n); break;
			case 2: cout<<"\nElimina el primer elemento de la Cola: ";
					quitar_pCola(Frente, Fin); break;		
			case 3: cout<<"\nElimina toda la cola: "; 
					eliminarCola(Frente, Fin); break;
			case 4: cout<<"\nImprimiendo Cola: "; 
					imprimirCola(Frente); break;
			case 5: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=5);
	
	return 0;
	
}


// Inserta elementos en la Cola
void insertarCola(Nodo *&Frente, Nodo*&Fin, int n){
	
	Nodo *nuevo_nodo = new Nodo(); // Creo nodo Auxiliar donde insertare cada dato
	nuevo_nodo->dato=n; //Insertar el valor en el Nodo
	nuevo_nodo->siguiente=NULL; // Siguiente apunta a NULL
	
	if (Frente==NULL & Fin==NULL){ // Entra cuando la cola esta vacia 
		
		Frente=nuevo_nodo;
		Fin=nuevo_nodo;
		
	}
	
	else { // Entra cuando la Cola esta con uno o más elementos
		
		Fin->siguiente = nuevo_nodo;
		Fin = nuevo_nodo;
		
	}
	
	cout<<"\nSe inserto el valor "<<nuevo_nodo->dato<<" correctamente"<<endl;
	
	
}


// Quita el elemento posicionado frente de la cola
void quitar_pCola (Nodo *& Frente, Nodo*& Fin){
	
	Nodo *aux = Frente;
	
	if (Frente != NULL){
		
		int n = Frente->dato;
		
		if(Frente==Fin){
		
			Frente=NULL;
			Fin=NULL;
			delete aux;	
			
		}
	
		else{
			
			Frente=Frente->siguiente;
			delete aux;
		}
	
		cout<<"\nHemos eliminado el valor "<<n;
		
	}
	
	if (Frente == NULL ){
		
		cout<<"\nLa Cola esta vacia"<<endl;
		
	} 
	
}

// Elimina toda la cola 
void eliminarCola (Nodo *&Frente, Nodo*& Fin){
	
	
	while (Frente != NULL){
		
		Nodo *aux = Frente;
		
		int n = Frente->dato;
		
		
		if(Frente==Fin){
		
			Frente=NULL;
			Fin=NULL;
			delete aux;	
			
		}
	
		else{
			
			Frente=Frente->siguiente;
			delete aux;
		}
	
		cout<<"\nHemos eliminado el valor "<<n;
		
	}
	
	if (Frente == NULL ){
		
		cout<<"\nLa Cola esta vacia"<<endl;
		
	} 
	
}


// Imprime la Cola
void imprimirCola(Nodo *Frente){
	
	Nodo *nuevo_nodo=Frente;
	
	if(Frente != NULL){
		
		while(nuevo_nodo != NULL){
		
			cout<<nuevo_nodo->dato<<" -> ";
			nuevo_nodo = nuevo_nodo->siguiente;		
		}	
		
		cout<<"NULL\n";
	}
	
	else{
		
		cout<<"La Cola esta vacia\n";
		
	}
	
}
