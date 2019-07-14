// Implementar una funcion que permita buscar un elemeno de una cola de productos (cadena de caracteres);

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Nodo{
	
	char dato;
	Nodo *siguiente;
	
};

void insertarCola(Nodo *&, Nodo*&, char[]);
void imprimirCola(Nodo *);
void buscarCola(Nodo *&, Nodo *&, char[]);

int main(){
	
	char n[20];

	int opc=0;
	
	Nodo *Frente = NULL;
	Nodo *Fin = NULL;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar un en la Cola"<<endl;
		cout<<"2. Imprimir los productos de la Cola"<<endl;
		cout<<"3. Busca un producto en la Cola"<<endl;
		cout<<"4. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; 	
					cin.getline(n,20,'\n'); 
					insertarCola(Frente, Fin, n); break;
			case 2: cout<<"\nImprimiendo Cola: "; 
					imprimirCola(Frente); break;
			case 3: cout<<"\nEscriba el elemento que desea buscar "; cin>>n;
					buscarCola(Frente, Fin,n); break;
			case 4: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=4);
	
	return 0;
	
}


// Inserta elementos en la Cola
void insertarCola(Nodo *&Frente, Nodo*&Fin, char n[]){
	
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

// Busca la posicion de un elemento en la Cola
void buscarCola(Nodo *&Frente, Nodo *&Fin, char n[]){
	
	Nodo *aux = Frente;
	int pos=1;
	int encontrado=0;
	
	cout<<"\n\t";
	
	if (aux != NULL){
		
		while (aux != NULL){
		
			if (aux->dato == n){
			
				encontrado = 1;
				break;
			
			}
		
		aux = aux -> siguiente;
		
		pos++;
		
		}
	
		if(encontrado == 1){
			
			cout<<"El elemento "<<aux->dato<<" en la posicion "<<pos<<endl;				
			
		}
		
		else cout<<"No existe ese numero en la Cola\n";	
		
		
	}
	
	else cout<<"La cola esta vacia\n";
	
}
