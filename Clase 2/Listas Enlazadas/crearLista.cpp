#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *sig;
	
};

int n;

void insertarLista(Nodo *&, int n);
void imprimirLista(Nodo *&);
void buscarLista(Nodo *&, int n);

int main(){
	
	Nodo *lista = NULL;
	int opc;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar nodo en la Lista"<<endl;
		cout<<"2. Elimina el primer nodo de la Cola"<<endl;
		cout<<"3. Eliminar toda la Cola"<<endl;
		cout<<"4. Imprimir Lista completa"<<endl;
		cout<<"5. Busca un elemento en la Lista"<<endl;
		cout<<"6. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					insertarLista(lista, n); break;
			case 4: cout<<"\nMostrando los datos de la lista: ";
					imprimirLista(lista); break;
			case 5: cout<<"\nEscriba el dato desea encontrar: "; cin>>n;
					buscarLista (lista, n); break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=6);
	
	return 0;
	
}


// Inserta elementos en la lista
void insertarLista(Nodo *&lista, int n){
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2; // Auxiliar para ordenar la lista
	
	// Ordena los elementos de menor a mayor
	/*while ((aux1 != NULL) && (aux1->dato < n)){
		
		aux2 = aux1;
		aux1 = aux1->sig;
		
	}*/
	
	if (lista == aux1){
		
		lista = nuevo_nodo;
		
	}
	
	/*else{
		
		aux2->sig = nuevo_nodo;
		
	}*/
	
	nuevo_nodo->sig = aux1;
	
	cout<<"\tSe inserto el valor "<<n<<" correctamente\n";
	
}

void imprimirLista(Nodo *& lista){
	
	Nodo *aux = lista;
	
	cout<<"\n\t";
	
	if (aux != NULL){
		
		while (aux != NULL){
		
		cout<<aux->dato<<" -> ";
		
		aux = aux -> sig;
		
	}
	
	cout<<"NULL"<<endl;	
		
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";
	
}

void buscarLista(Nodo *& lista, int n){
	
	Nodo *aux = lista;
	int pos=1;
	int encontrado=0;
	
	cout<<"\n\t";
	
	if (aux != NULL){
		
		while (aux != NULL){
		
			if (aux->dato == n){
			
				encontrado = 1;
				break;
			
			}
		
		aux = aux -> sig;
		
		pos++;
		
		}
	
		if(encontrado == 1){
			
			cout<<"El elemento "<<aux->dato<<" en la posicion "<<pos<<endl;				
			
		}
		
		else cout<<"No existe ese numero en la Lista\n";	
		
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";
	
}
