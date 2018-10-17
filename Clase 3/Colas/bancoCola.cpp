// Programa que simule un banco donde entran clientes(nuevos y titulares). Los titulares van siempre primero en la cola y luego los clientes, osea hay mas prioridad pro atender a los titulares.


#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int pri;
	int dato;
	Nodo *siguiente;
	
};

void insertarCola(Nodo *&, Nodo*&, int, int);
void ordenarCola(Nodo *&, Nodo*&, int);
void quitar_pCola (Nodo *&, Nodo*&);
void imprimirCola(Nodo *);

int contador=0; // Cuenta el numero total de elementos

int main(){
	
	int n;
	int opc=0;
	int prio;
	
	Nodo *Frente = NULL;
	Nodo *Fin = NULL;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Entra un cliente al banco"<<endl;
		cout<<"2. Sale un cliente de la Cola"<<endl;
		cout<<"3. Imprimir clientes en la Cola"<<endl;
		cout<<"4. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEste cliente es un titular o nuevo:\n"; 
					cout<<"\t1. Titular\n";
					cout<<"\t2. Nuevo\n";
					
					cout<<"\nInserte Opcion: "; cin>>prio;
					
					n=prio;
					
					if (prio == 1){
						
						contador++;
						insertarCola(Frente, Fin, n, prio); break;
						
					}
					
					else if  (prio == 2){
						
						contador++;
						insertarCola(Frente, Fin, n, prio); break;
						
					}
					
					else{
						
						cout<<"No inserto ninguna opcion\n"; break;
						
					}					
			case 2: cout<<"\nEl primer cliente se ha ido"<<endl;
					contador--;
					quitar_pCola(Frente, Fin); break;
			case 3: cout<<"\nImprimiendo clientes de la Cola: "; 
					imprimirCola(Frente); break;
			case 4: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=4);
	
	return 0;
	
}

// Inserta elementos en la Cola
void insertarCola(Nodo *&Frente, Nodo*&Fin, int n, int prio){
	
	Nodo *nuevo_nodo = new Nodo(); // Creo nodo Auxiliar donde insertare cada dato
	nuevo_nodo->dato=n; //Insertar el valor en el Nodo
	nuevo_nodo->siguiente=NULL; // Siguiente apunta a NULL
	nuevo_nodo->pri=prio; // Inserta la priorida (Si es titular o nuevo)
	
	if (Frente==NULL & Fin==NULL){ // Entra cuando la cola esta vacia 
		
		Frente=nuevo_nodo;
		Fin=nuevo_nodo;
		
	}
	
	else { // Entra cuando la Cola esta con uno o más elementos
		
		Fin->siguiente = nuevo_nodo;
		Fin = nuevo_nodo;
		
	}
	
	ordenarCola(Frente, Fin, contador);
	
	if (nuevo_nodo->pri==1){
		
		cout<<"Ha entrado un Titular a la Cola\n";
		
	}
	
	if (nuevo_nodo->pri==2){
		
		cout<<"Ha entrado un Cliente Nuevo a la Cola\n";
		
	}
	
}

// Ordena la cola segun sus prioridades
void ordenarCola(Nodo *&Frente, Nodo*&Fin, int cont){
	
	Nodo *aux;
	Nodo *aux2;
	int auxiliar;
	int i;
	
	for (i=1; i<cont; i++){
		
		aux=Frente;
		
		while (aux -> siguiente != NULL){
		
			if (aux -> pri == 1) {
				
		 		aux = aux -> siguiente;
				
			}
		
			else{
			
				aux2=aux->siguiente; 
			
				if(aux2 -> pri == 2){
				
					aux = aux->siguiente;
				
				}
			
				else{
				
					auxiliar = aux -> dato;
					aux -> dato = aux2 -> dato;
					aux2 -> dato = auxiliar;
				
					aux -> pri = 1;
					aux2 -> pri = 2;
				
					aux = aux->siguiente;
				}
			
			}
		
		}
		
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
