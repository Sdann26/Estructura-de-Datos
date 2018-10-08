#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *siguiente;
	
};

void insertarCola(Nodo *&, Nodo*&, int);

int main(){
	
	int n;
	int opc=0;
	
	Nodo *Frente = NULL;
	Nodo *Fin = NULL;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar Nodo en Cola"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					insertarCola(Frente, Fin, n); break;
			case 2: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=3);
	
	return 0;
	
}

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
