// Programa para unir colas

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *siguiente;
	
};

int n1;
int n2;
int n;

void insertarCola(Nodo *&, Nodo*&, int);
void imprimirCola(Nodo *);
void unirColas(Nodo *&, Nodo*&, Nodo*, Nodo* );

int main(){

	int i;
	
	Nodo *frente1 = NULL;
	Nodo *fin1 = NULL;
	
	Nodo *frente2 = NULL;
	Nodo *fin2 = NULL;
	
	Nodo *frente3=NULL;
	Nodo *fin3=NULL;
	
	cout<<"Cuantos valores insertaras en la primera cola: ";	cin>>n1;
	cout<<endl;
	
	for(i=0 ; i<n1; i++){
		
		cout<<"Insertar valor: "; cin>>n;
		insertarCola(frente1, fin1, n);
		
	}
	
	cout<<"Cola 1: ";
	imprimirCola(frente1);
	cout<<endl;
	
	cout<<"Cuantos valores insertaras en la segunda cola: ";	cin>>n2;
	cout<<endl;
	
	
	for(i=0 ; i<n2; i++){
		
		cout<<"Insertar valor: "; cin>>n;
		insertarCola(frente2, fin2, n);
		
	}
	
	cout<<"Cola 2: "; 
	imprimirCola(frente2);
	cout<<endl;
	
	cout<<"Uniendo las dos colas anteriores en una sola: "<<endl;
	cout<<"Cola 3: "; 
	unirColas(frente3,fin3,frente1,frente2);
	imprimirCola(frente3);
	cout<<endl;
	
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
	
	cout<<"\nSe inserto el valor "<<nuevo_nodo->dato<<" correctamente\n"<<endl;
	
	
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

// Une la segunda cola al final de la primera
void unirColas(Nodo *&frente3, Nodo *&fin3, Nodo *frente1, Nodo *frente2){
	
	int i;
	
	for(i=0; i<n1; i++){
		
		insertarCola(frente3, fin3, frente1->dato);
		frente1=frente1->siguiente;
		
	}
	
	for(i=0; i<n2; i++){
		
		insertarCola(frente3, fin3, frente2->dato);
		frente2=frente2->siguiente;
		
	}
	
}
