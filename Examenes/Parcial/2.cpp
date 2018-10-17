/*Una alternativa a la estrategia de eliminacion es la eliminacion peresoza. Para borrar un elemento, solo se marca como eliminado(usando un campo adicional). El numero de elementos eliminados y no eliminados se mantiene como parte de la estructura de datos. Si la cantidad de elementos eliminados es mayor igual a la cantidad de elementos no eliminados, se recorre la lista completa y se elimina los nodos marcados*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Nodo{
	
	int eli=1; // Verifica si sera eliminado o no
	int dato;
	Nodo *sig;
	
};

int eliminados=0, no_eliminados;

void insertarLista(Nodo *&, int );
void quitarLista(Nodo *& , int ,int &, int &);
void eliminarLista(Nodo *&, int);
void imprimirLista(Nodo *&);

int main(){
	
	Nodo *lista = NULL;
	
	int n;
	int x;
	int i;

	cout<<"Cuantos valores iniciales tiene la lista n: ";
	cin>>n;
	no_eliminados=n; //Guardara siempre la cantidad de elementos
	cout<<endl;
	
	for (i=1 ;i<=n ;i++){
		
		cout<<"Inserte valor: ";	cin>>x;
		insertarLista(lista,x);
			
	}
	
	int opc;
	
	do {
		
		cout<<"MENU:\n"<<endl;
		
		cout<<"1. Insertar nodo en la Lista"<<endl;
		cout<<"2. Elimina un elemento de la Lista"<<endl;
		cout<<"3. Imprimir Lista completa"<<endl;
		cout<<"4. Salir"<<endl;
		
		cout<<"\nEscriba su opcion: ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1: cout<<"\nEscriba el dato desea insertar: "; cin>>n; no_eliminados++;
					insertarLista(lista, n); break;
			case 2: cout<<"\nEscriba el dato desea eliminar: "; cin>>n;
					quitarLista(lista, n, eliminados, no_eliminados); break;
			case 3: cout<<"\nMostrando los datos de la lista: ";
					imprimirLista(lista); break;
			case 4: break;
			default: cout<<"\nNo ha insertado ninguna de las opciones";
			
		}
		
		
		// Funcion cuando ya halla mas elementos eliminados que no eliminados
		if (eliminados >= no_eliminados){
			
			cout<<"Ya hay mas elementos eliminados que no eliminados se pasara a eliminarlos de la lista"<<endl;
			eliminarLista(lista, eliminados);
			break;
			
		}
		
		cout<<"\n\n";	
		
	}while(opc!=4);
	
	cout<<"\nEstos son los elementos que quedan:\n";
	imprimirLista(lista);
	
	cout<<"\n\tGracias por utilizar mi programa\n";
	cout<<"\t\t\tBy: Danilo Blas"<<endl;
	
	
	return 0;
	
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

void insertarLista(Nodo *&lista, int n){
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->sig = NULL;
	
	Nodo *aux1 = lista;
	Nodo *aux2; // Auxiliar para ordenar la lista
	
	// Ordena los elementos de menor a mayor
	/*while ((aux1 != NULL) && (aux1->dato < n)){
		
		aux2 = aux1;
		aux1 = aux1->sig;
		
	}*/
	
	if (aux1 == NULL){
		
		lista = nuevo_nodo;
		
	}
	
	/*else{
		
		aux2->sig = nuevo_nodo;
		
	}*/
	
	else {
		
		while(aux1 -> sig != NULL){
			
			aux1 = aux1 -> sig;
			
		}
			
		aux1 -> sig = nuevo_nodo;
		
	}
	
	cout<<"\tSe inserto el valor "<<n<<" correctamente\n";
	
}

// Marca en 0 el elemento que se quiere eliminar
void quitarLista(Nodo *& lista, int n, int& eliminados, int& no_eliminados){
	
	if (lista != NULL){
		
		Nodo *aux = lista;
		Nodo *anterior = NULL;
		
		// Recorre la lista
		while ((aux != NULL) && (aux->dato != n)){
		
			anterior = aux;
			aux = aux -> sig;
			
		}
		
		
		// No existe el elemento en la lista
		
		if(aux == NULL){
			
			cout<<"El elemento no existe"<<endl;
			
		}
		
		// Elemento encontrado en la primera posicion
		else if(anterior== NULL){
			
			aux -> eli = 0;
			eliminados++; no_eliminados--;
		}
		
		// Elimina el elemento encontrado en la lista pero no es el primero
		else{
			
			aux -> eli = 0;
			eliminados++; no_eliminados--;	
		}
		
		
		
		
	}
	
	else cout<<"\nLa Lista esta vacia\n";
	
}

void eliminarLista(Nodo *&lista, int eliminados){

	int i;
		
	for (i=1; i<=eliminados; i++){
			
		Nodo *aux = lista;
		Nodo *anterior = NULL;
		
		// Busca el elemento a eliminar
		while ((aux != NULL) && (aux->eli != 0)){
		
			anterior = aux;
			aux = aux -> sig;
			
		}
		
		// En el caso que este en el inicio
		if(anterior == NULL){
			
			lista = lista -> sig;
			delete aux;
			
		}
		
		// En el caso que no este en el inicio
		else{
			
			anterior -> sig = aux -> sig;
			delete aux;		
		}
		
			
	}	
	
}
