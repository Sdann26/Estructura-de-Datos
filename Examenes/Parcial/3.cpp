// En un pequeño supermercado dispone en la salida de 3 cajas de pago. en el local hay 25 carritos de compra. Escribir un programa que simule el funcionamiento siguiente 4 reglas.
// 1. Cuando no haya carritos los clientes se quedaran esperando afuera hasta que haya carritos disponibles
// 2. Cuando entren clientes estos se quedaran haciendo compras. 
// 3. Una vez que terminen se iran a la caja con la cola menos larga.
// 4. Cuando decidan salir de alguna caja, habra un nuevo carrito disponible para nuevos clientes o clientes que esperan.

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

int main(){
	
	int n=5;
	int opc1=0;
	int opc2=0;
	int max=25; // Maximo de carritos
	int cliente = 0; // Numero de clientes que pasan por la cola
	int clientes_fuera=0; // Clientes que aun no entran
	
	Nodo *Frente1 = NULL;
	Nodo *Fin1 = NULL;
	int n1=0;
	
	Nodo *Frente2 = NULL;
	Nodo *Fin2 = NULL;
	int n2=0;
	
	Nodo *Frente3 = NULL;
	Nodo *Fin3 = NULL;
	int n3=0;
	
	cout<<"\nEn el supermercado hay 25 carritos disponibles\n";
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Llega un cliente"<<endl;
		cout<<"2. Un cliente finalizo su compra"<<endl;
		cout<<"3. El cliente ya sale de la caja"<<endl;
		cout<<"4. Cola de la Caja 1"<<endl;
		cout<<"5. Cola de la Caja 2"<<endl;
		cout<<"6. Cola de la Caja 3"<<endl;
		cout<<"7. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc1;
		
		
		switch (opc1){
			
			case 1: if (max>0){
			
					max=max-1; // Hay menos carritos disponibles
					cout<<"\nEste cliente toma un carrito, quedan "<<max;
					cliente++; // Hay un cliente mas
					}
					
				  else {
				  	
				  	cout<<"\nEste cliente quedara esperando fuera";
				  	clientes_fuera++; // En el caso que haya clientes fuera
				  	
				  	}
				  break;	
				
			case 2: if(cliente>0){
					cout<<"\nUn cliente pasa por una cola";
					if(n1<=n2 && n1<=n3){
					
						cout<<"\nEntra a la cola 1\n";
						insertarCola(Frente1,Fin1, 1);  //El valor que se le da no importa
						n1++; // Hay un elemento mas en la cola 1
						cliente--; // Un cliente menos que atender
						break;
					
						}
					else if(n2 <= n3){
					
						cout<<"\nEntra a la cola 2\n";
						insertarCola(Frente2,Fin2, 1); //El valor que se le da no importa
						n2++; // Hay un elemento mas en la cola 2
						cliente--; // Un cliente menos que atender
						break;
					
						}
						
					else {
						
						cout<<"\nEntra a la cola 3\n";
						insertarCola(Frente3,Fin3, 1); //El valor que se le da no importa
						n3++; // Hay un elemento mas en la cola 3
						cliente--; // Un cliente menos que atender
						break;
						
						}
					}
				  else cout<<"\nNo hay clientes realizando compra\n"; break;
					
					
			case 3: cout<<"\nElija de que caja salir: "; 
					cin>>opc2;
					switch (opc2){
						case 1: if(n1>0){
								quitar_pCola (Frente1, Fin1); 
								n1--; // Hay un elemento menos en la cola 1
								max ++; // Hay mas carritos disponibles
								cout<<"\nAhora hay "<<max<<" carritos disponibles\n";
								}
							  else cout<<"\nNo hay nadie en la cola\n";
							  
							  // Verificamos si hay gente afuera
							  if(clientes_fuera>0){
							  	max=max-1; // Hay menos carritos disponibles
								cout<<"\nEste cliente afuera toma un carrito";
								cliente++; // Hay un cliente mas
								clientes_fuera--; // Un cliente ya no hace cola afuera
							  	}
							  	
							  break;
						case 2: if(n2>0){
								quitar_pCola (Frente2, Fin2); 
								n2--; // Hay un elemento menos en la cola 2
								max ++; // Hay mas carritos disponibles
								cout<<"\nAhora hay "<<max<<" carritos disponibles\n";
								}
							  else cout<<"\nNo hay nadie en la cola\n";
							  
							  // Verificamos si hay gente afuera
							  if(clientes_fuera>0){
							  	max=max-1; // Hay menos carritos disponibles
								cout<<"\nEste cliente afuera toma un carrito";
								cliente++; // Hay un cliente mas
								clientes_fuera--; // Un cliente ya no hace cola afuera
							  	}
							  	
							  break;
						case 3: if(n3>0){
								quitar_pCola (Frente3, Fin3); 
								n3--; // Hay un elemento menos en la cola 3
								max ++; // Hay mas carritos disponibles
								cout<<"\nAhora hay "<<max<<" carritos disponibles\n";
								}
							  else cout<<"\nNo hay nadie en la cola\n";
							  
							  // Verificamos si hay gente afuera
							  if(clientes_fuera>0){
							  	max=max-1; // Hay menos carritos disponibles
								cout<<"\nEste cliente afuera toma un carrito";
								cliente++; // Hay un cliente mas
								clientes_fuera--; // Un cliente ya no hace cola afuera
							  	}
							  	
							  break;
						default: cout<<"\nNo ha insertado ninguna caja";
					}
					break;
			case 4: cout<<"\nCola: "; imprimirCola(Frente1); break;
			case 5: cout<<"\nCola: "; imprimirCola(Frente2); break;
			case 6: cout<<"\nCola: "; imprimirCola(Frente3); break;
			case 7: cout<<"\nSalir."; break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc1!=7);
	
	cout<<"\n\tGracias por utilizar mi programa\n";
	cout<<"\t\t\tBy: Danilo Blas"<<endl;
	
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
	
	else { // Entra cuando la Cola esta con uno o mÃ¡s elementos
		
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
	
	if (Frente == NULL ){
		
		cout<<"\nYa no hay clientes en la cola"<<endl;
		
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
