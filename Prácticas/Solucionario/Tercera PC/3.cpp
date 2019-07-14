// Un estacionamiento de autos contiene una sola linea la cual tiene capacidad hasta para 10 carros.
// Los carros llegan del extremo sur y salen por el norte. Si un cliente llega recoger su carro que no esta muy hacia al norte, todos los carros al norte de su carro son retirados, saca su carro y los otros carros son colocados de nuevo en el mismo orden en que estaban originalmente. Cada vez que sale un carro, todos los carros que estan al sur son movidos hacia delante, de tal manera que en todo momento todos los espacios vacios estan en la parte sur del estacionamiento.
// Escriba un programa que simule el funcionamiento de un estacionamiento usando colas. Debe imprimir un mensaje cada ves que llega un carro, Cuando sale un carro, el mensaje debe incluir el numero de veces que fue movido el carro dentro del estacionamiento

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *siguiente;
	
};

void insertarCola(Nodo *&, Nodo*&, int);
void quitar_pCola (Nodo *&, Nodo*&);
void imprimirCola(Nodo *);
void buscarCola(Nodo *&, Nodo *&, int, int &);

int main(){
	
	int n;
	int opc=0;
	
	Nodo *Norte = NULL;
	Nodo *Sur = NULL;
	
	int total_esp=10; // Espacios para los carros
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar carro en el estacionamiento"<<endl;
		cout<<"2. Sacar un carro del estacionamiento"<<endl;
		cout<<"3. Imprimir Cola completa"<<endl;
		cout<<"4. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: 	if (total_esp>0){
						cout<<"\nSi hay espacio para este carro\n";
						cout<<"\nEscriba el numero de carro del cliente: "; cin>>n; 
						insertarCola(Norte, Sur, n);
						total_esp--; // Disminuye la cantidad de espacios en el estacionamiento
				  	}
				  	else cout<<"\nNo hay espacio para este carro\n";
				  	break;
			case 2: 	cout<<"\nEscriba el numero de carro que desea sacar "; cin>>n;
					buscarCola(Norte, Sur,n, total_esp); break;
			case 3: 	cout<<"\nImprimiendo la cola del estacionamiento: "; 
					imprimirCola(Norte); break;
			case 4: 	break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=4);
	
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
		
	}	
}

// Imprime la Cola
void imprimirCola(Nodo *Frente){
	
	Nodo *nuevo_nodo=Frente;
	
	if(Frente != NULL){
		
		cout<<"\nNORTE ";
		
		while(nuevo_nodo != NULL){
		
			cout<<nuevo_nodo->dato<<" <- ";
			nuevo_nodo = nuevo_nodo->siguiente;		
		}	
		
		cout<<"SUR\n";
	}
	
	else{
		
		cout<<"La Cola esta vacia\n";
		
	}
	
}

// Busca la posicion de un elemento en la Cola
void buscarCola(Nodo *&Frente, Nodo *&Fin, int n, int &total_esp){
	
	Nodo *aux = Frente;
	
	int pos=1; // Cantidad de veces que fue movido el carro
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
			
			cout<<"Fue movido "<<pos<<" veces el carro "<<aux->dato<<endl;
			total_esp++; // Aumenta la cantidad de espacios en el estacionamiento				
			
		}
		
		else cout<<"No existe ese numero en la Cola\n";	
		
		
	}
	
	else cout<<"La cola esta vacia\n";
	
	//Una vez que encontramos el carro creamos una cola que guardara todos los valores menos el eliminado
	
	int i;
	Nodo *nuevo = NULL; // Cola que guardara los carros que se quedan
	Nodo *fin_n=NULL;
	Nodo *aux_nuevo = nuevo; // Auxiliar de esta cola
	
	for (i=1; i<pos; i++){ // Elimina los varros al norte del carro buscado

		insertarCola(nuevo, fin_n, Frente->dato);
		
		quitar_pCola (Frente, Fin);
		
	}
	
	quitar_pCola (Frente, Fin); // Eliminando el carro buscado
	
	while (Frente != NULL){ // Elimina los varros al norte del carro buscado
		
		insertarCola(nuevo, fin_n, Frente->dato);
		
		quitar_pCola (Frente, Fin);
		
	}
	
	while (nuevo != NULL){ 
		
		insertarCola(Frente, Fin, nuevo->dato);
		
		quitar_pCola (nuevo, fin_n);
		
	}
	
}
