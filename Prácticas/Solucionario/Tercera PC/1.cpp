// Obtener los elementos de la sucesiÃ³n de Fibonacci (1,1,2,3,5,8)

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{

       int dato;
       Nodo *siguiente;

};

int n;

// Prototipo de funcion
void agregarPila (Nodo *& ,int );
void imprimirPila (Nodo *);

int main(){

	Nodo *pila=NULL;
	int dato;
	int n;
	int i;
    
    	agregarPila (pila, 1);
    	agregarPila (pila, 1);
    	
	cout<<"\nHasta que valor de la serie de Fibonacci desea: ";
	cin>>n;


	// Variables para el Fibonacci
	int aux;
	int a=1;
	int b=1;

	for (i=3; i<=n; i++){
	
		aux=a+b;
		a=b;
		b=aux;
		
		agregarPila (pila, b);
	
	}
	
	if (n==1){
	
		cout<<"\n1 -> NULL\n";
	
	}
	
	else if (n==2){
	
		cout<<"\n1 -> 1 ->NULL\n";
	
	}
	
	else{
	
		imprimirPila (pila);

	}	

	cout<<"\nGracias por usar mi programa vuelva pronto\n\n";

	return 0;
	

}

void agregarPila (Nodo *&pila ,int n){

      Nodo *nuevo_nodo = new Nodo(); // Reservamos memoria para un nuevo nodo (Auxiliar)

      nuevo_nodo->dato = n; // Le asigna un valor al nuevo_nodo
      nuevo_nodo->siguiente = pila; // Al Nodo siguiente le asigna la direccion de pila que apunta a NULL
      pila = nuevo_nodo; // Nuestra Pila principal se vuelve el nuevo_nodo

}

void imprimirPila (Nodo *pila){

	int i;

	if (pila != NULL){
	
		cout<<endl;
	
		while(pila != NULL){

   	    	Nodo *nuevo_nodo = pila;
   	    	pila = nuevo_nodo->siguiente;
    		cout<<nuevo_nodo->dato<<" -> ";

		}
		
		cout<<"NULL\n";
	
	}

	else cout<<"La Pila esta vacia\n";

}
