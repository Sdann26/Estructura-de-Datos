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
void buscarLista(Nodo *&, int );
void quitarLista(Nodo *& , int );
void eliminarLista(Nodo *&);
void mayorLista(Nodo *lista);
void menorLista(Nodo *lista);

int main(){
	
	Nodo *lista = NULL;
	int opc;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar nodo en la Lista"<<endl;
		cout<<"2. Elimina un elemento de la Lista"<<endl;
		cout<<"3. Eliminar toda la Lista"<<endl;
		cout<<"4. Imprimir Lista completa"<<endl;
		cout<<"5. Busca un elemento en la Lista"<<endl;
		cout<<"6. Elemento mayor de la Lista"<<endl;
		cout<<"7. Elemento menor de la Lista"<<endl;
		cout<<"8. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; 
					insertarLista(lista, n); break;
			case 2:	cout<<"\nEscriba el dato desea eliminar: "; cin>>n;
					quitarLista(lista, n); break;
			case 3: cout<<"Eliminando toda la Lista"<<endl;
					eliminarLista(lista); break;
			case 4: cout<<"\nMostrando los datos de la lista: ";
					imprimirLista(lista); break;
			case 5: cout<<"\nEscriba el dato desea encontrar: "; cin>>n;
					buscarLista (lista, n); break;
			case 6:	mayorLista(lista); break;
			case 7: menorLista(lista); break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		cout<<"\n\n";
		
	}while(opc!=8);
	
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

void quitarLista(Nodo *& lista, int n){
	
	int encontrado = 0;
	
	if (lista != NULL){
		
		Nodo *aux = lista;
		Nodo *anterior = NULL;
		
		while ((aux != NULL) && (aux->dato != n)){
		
			anterior = aux;
			aux = aux -> sig;
			
		}
		
		if(anterior == NULL){
			
			lista = lista -> sig;
			delete aux;
			encontrado = 1;
			
		}
		
		else{
			
			anterior -> sig = aux -> sig;
			delete aux;	
			encontrado = 1;		
		}
	
		if(encontrado == 1){
			
			cout<<"El elemento "<<n<<" ha sido eliminado"<<endl;				
			
		}
		
		else cout<<"No existe ese numero en la Lista\n";	
		
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";
	
}

void eliminarLista(Nodo *&lista){
		
	if (lista != NULL){
		
		while (lista != NULL){
			
			Nodo *aux = lista;		
			lista = lista -> sig;
			delete aux;
			
		}
		
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";	
	
}

void mayorLista(Nodo *lista){
		
	int val = lista->dato;
		
	if (lista != NULL){
		
		Nodo *aux = lista;
		
		while (aux != NULL){
			
			if (aux -> dato > val){
				
				val = aux -> dato;
				
			}
			
			aux = aux -> sig;
			
		}
		
		
		cout<<"\nEl valor mayor es: "<<val<<"\n";
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";	
	
}

void menorLista(Nodo *lista){
		
	int val = lista->dato;
		
	if (lista != NULL){
		
		Nodo *aux = lista;
		
		while (aux != NULL){
			
			if (aux -> dato < val){
				
				val = aux -> dato;
				
			}
			
			aux = aux -> sig;
			
		}
		
		
		cout<<"\nEl valor menor es: "<<val<<"\n";
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";	
	
}
