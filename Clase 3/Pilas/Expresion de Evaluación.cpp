// Programa de Expresion de Evaluacion: Le pasaremos un valor inicial y luego cada valor que agreguemos sera junto a una operacion lo cual al final nos devolvera

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{

       int dato;
       Nodo *siguiente;

};

void agregarPila (Nodo *& ,int );
void eliminarPila(Nodo *&);
void imprimirPila (Nodo *);

int main(){

    Nodo *pila=NULL;
    int opc;
    int n;
    
	do {
		
		cout<<"\nMENU:\n"<<endl;
		cout<<"Presione 1 si desea insertar nuevo valor: "<<endl;
		cout<<"Presione 2 si desea ver el resultado"<<endl;
		cout<<"Presione 3 si desea salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					agregarPila(pila, n); break;
			case 2: imprimirPila (pila); break;
			case 3: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(opc!=3);

	system("CLS");
	
	cout<<"\nGracias por usar el programa\n"<<endl;

    system("PAUSE");
    return 0;

}

// Agrega nodos a la Pila
void agregarPila (Nodo *&pila ,int n){

    Nodo *nuevo_nodo = new Nodo(); // Reservamos memoria para un nuevo nodo (Auxiliar)
	
	int opc;
	int resul;
	int a;
	int b;
	
	if(pila == NULL){
		
		nuevo_nodo->dato = n; // Le asigna un valor al nuevo_nodo
    	nuevo_nodo->siguiente = pila; // Al Nodo siguiente le asigna la direccion de pila que apunta a NULL
    	pila = nuevo_nodo; // Nuestra Pila principal se vuelve el nuevo_nodo
		
	}
	
	else {
		
		nuevo_nodo->dato = n; // Le asigna un valor al nuevo_nodo
    	nuevo_nodo->siguiente = pila; // Al Nodo siguiente le asigna la direccion de pila que apunta a NULL
    	pila = nuevo_nodo; // Nuestra Pila principal se vuelve el nuevo_nodo
		
		cout<<"\nMENU DE OPERACIONES:\n"<<endl;
		cout<<"Que operacion va aplicar:\n\n";	
		
		cout<<"1. Suma"<<endl;
		cout<<"2. Resta"<<endl;
		cout<<"3. Multiplicacion"<<endl;
		cout<<"4. Division"<<endl;

		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: b=pila->dato;
					nuevo_nodo=pila->siguiente;
					a=nuevo_nodo->dato;
					resul=a+b;
					eliminarPila(pila);
					agregarPila (pila, resul);
					break;
			case 2: b=pila->dato;
					nuevo_nodo=pila->siguiente;
					a=nuevo_nodo->dato;
					resul=a-b;
					eliminarPila(pila);
					agregarPila (pila, resul);
					break;
			case 3: b=pila->dato;
					nuevo_nodo=pila->siguiente;
					a=nuevo_nodo->dato;
					resul=a*b;
					eliminarPila(pila);
					agregarPila (pila, resul);
					break;
			case 4: b=pila->dato;
					nuevo_nodo=pila->siguiente;
					a=nuevo_nodo->dato;
					resul=a/b;
					eliminarPila(pila);
					agregarPila (pila, resul);
					break;
			
		}   	
    	
	}

}

void eliminarPila (Nodo *&pila){


    // Verificamos si la Pila esta vacia
    while (pila != NULL){

        Nodo *nuevo_nodo = pila;
        pila = nuevo_nodo->siguiente;

        delete nuevo_nodo;

    }

}

void imprimirPila (Nodo *pila){
	
	if (pila != NULL){
		
		cout<<"\n\nEl valor resultado es: "<<pila->dato<<endl;
		
	}
	
	else cout<<"Aun no hay valores en la pila"<<endl;
	
}
