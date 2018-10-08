// Reemplaza el valor viejo en la pila por un valor nuevo

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
void quitarPila (Nodo *&);
void eliminarPila(Nodo *&);
void imprimirPila (Nodo *);
void reemplazarPila (Nodo *&, int ,int );

int main(){

    Nodo *pila=NULL;
    int dato;
    int i;
    int opc; // Aca pondremos la opcion a elegir
    int viejo, nuevo; 

	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar Nodo en la Pila"<<endl;
		cout<<"2. Quitar Nodo de la Pila"<<endl;
		cout<<"3. Eliminar toda la Pila"<<endl;
		cout<<"4. Reemplazar un elemento nuevo por uno viejo de la Pila"<<endl;
		cout<<"5. Imprimir Pila completa"<<endl;
		cout<<"6. Salir"<<endl;
		
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					agregarPila(pila, n); break;
			case 2: cout<<"\nElimina el ultimo elemento insertado en la Pila: "; 
					quitarPila(pila); break;
			case 3: cout<<"\nElimina toda la Pila: "; 
					eliminarPila(pila); break;
			case 4: cout<<"\nInserte el elemento a ser reemplazado: "; cin>>viejo;
					cout<<"\nInserte el nuevo elemento: "; cin>>nuevo;
					reemplazarPila (pila, viejo ,nuevo); break;			
			case 5: cout<<"\nImprimiendo Cola: "; 
					imprimirPila(pila); break;
			case 6: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(opc!=6);
	
	system("CLS");

	cout<<"\nGracias por usar mi programa vuelva pronto\n\n";

    system("PAUSE");
    return 0;

}

// Agrega nodos a la Pila
void agregarPila (Nodo *&pila ,int n){

     Nodo *nuevo_nodo = new Nodo(); // Reservamos memoria para un nuevo nodo (Auxiliar)

     nuevo_nodo->dato = n; // Le asigna un valor al nuevo_nodo
     nuevo_nodo->siguiente = pila; // Al Nodo siguiente le asigna la direccion de pila que apunta a NULL
     pila = nuevo_nodo; // Nuestra Pila principal se vuelve el nuevo_nodo

	 cout<<"\nSe inserto el valor "<<nuevo_nodo->dato<<" correctamente"<<endl;

}

// Quita el ultimo elemento de la Pila
void quitarPila (Nodo *&pila){


    // Verificamos si la Pila esta vacia
    if (pila != NULL){

        Nodo *nuevo_nodo = pila;
        pila = nuevo_nodo->siguiente;
        cout<<"\nEliminamos el valor: "<<nuevo_nodo->dato<<endl;

        delete nuevo_nodo;

    }

    else{

        cout<<"La Pila esta vacia";

    }
}

void eliminarPila (Nodo *&pila){


    // Verificamos si la Pila esta vacia
    while (pila != NULL){

        Nodo *nuevo_nodo = pila;
        pila = nuevo_nodo->siguiente;
        cout<<"Eliminamos el valor: "<<nuevo_nodo->dato<<endl;

        delete nuevo_nodo;

    }

    cout<<"La Pila esta vacia";

}


// Imprime lo que hay en la Pila
void imprimirPila (Nodo *pila){

	int i;

	if (pila != NULL){
	
	
		while(pila != NULL){

   	    	Nodo *nuevo_nodo = pila;
   	    	pila = nuevo_nodo->siguiente;
    		cout<<nuevo_nodo->dato<<" -> ";

		}
		
		cout<<"NULL\n";
	
	}

	else cout<<"La Pila esta vacia\n";

}


//Reemplaza el viejo elemento por uno nuevo
void reemplazarPila (Nodo *&pila, int viejo, int nuevo ){

	int i;

	Nodo *aux = pila;

	while(aux != NULL){

 		if (viejo == aux->dato){

 			aux->dato = nuevo;

		}

		aux = aux->siguiente;

	}

}
