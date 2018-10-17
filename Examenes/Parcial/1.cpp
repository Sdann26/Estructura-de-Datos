/*Supongamos que una lista L, y otra lista P, contienen enteros y estan clasificados en orden ascendentes. La operacion visualizarlotes(L,P) imprimira los elementos de L que estan en posiciones dadas por P. Por ejemplo si P: 1,3,4,6, se imprimira los elementos primero, tercero, cuarto y sexto de L*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo *sig;
	
};


void insertarLista(Nodo *&, int );
void visualizarlotes(Nodo *&,Nodo *&);
void imprimirLista(Nodo *&);

int main(){
	
	Nodo *L = NULL; //Lista L
	Nodo *P = NULL; //Lista P
	
	int n;
	int n1;
	int n2;
	int i;

	cout<<"Cuantos valores tiene la lista P: ";
	cin>>n1;
	cout<<endl;
	
	for (i=1 ;i<=n1 ;i++){
		
		cout<<"Inserte valor: ";	cin>>n;
		insertarLista(P,n);
			
	}
	
	
	// Aviso al usuario
	cout<<"\n\nADVERTENCIA: Tener en cuenta que la lista P son las posiciones que buscara en la lista L asi que el mayor valor de la lista P debe ser por lo menos la minima cantidad de elementos de la lista L\n\n";
	
	cout<<"\n\nValores de la lista P: ";
	imprimirLista(P);
	cout<<endl;
	
	cout<<"Cuantos valores tiene la lista L: ";
	cin>>n2;
	cout<<endl;
	
	srand(time(NULL));
	
	// Agrego valores aleatorios
	for(i=1; i<=n2; i++){
		
		n=rand()%40+1;
		insertarLista(L,n);
			
	}
	
	cout<<"\nValores de la lista 2: ";
	imprimirLista(L);
	cout<<endl;
	
	cout<<"\nMostrando los valores que pide la lista P: "<<endl;
	visualizarlotes(P,L);
	cout<<endl;

	
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
	
	Nodo *aux1 = lista;
	Nodo *aux2; // Auxiliar para ordenar la lista
	
	// Ordena los elementos de menor a mayor
	while ((aux1 != NULL) && (aux1->dato < n)){
		
		aux2 = aux1;
		aux1 = aux1->sig;
		
	}
	
	if (lista == aux1){
		
		lista = nuevo_nodo;
		
	}
	
	else{
		
		aux2->sig = nuevo_nodo;
		
	}
	
	nuevo_nodo->sig = aux1;
	
	cout<<"\tSe inserto el valor "<<n<<" correctamente\n";
	
}

void visualizarlotes(Nodo *&P,Nodo *&L){
	
	int i;
	Nodo *aux;
	
	// Pasa por cada elemento de P
	while(P != NULL){	
			
		aux = L;
			
		// Realiza el numero de vueltas para encontrar la posicion de L	
		for (i=1; i < P->dato; i++){
			
			aux = aux -> sig;
			
			if(aux == NULL){
			
				break;
			
			}
		}	
		
		
		if(aux == NULL){
		
			cout<<"No existe elemento en esa posicion\n";
			
		}
		
		else cout<<"En la posicion "<<P -> dato<<" esta el valor "<<aux -> dato<<endl;
		
		P = P -> sig; 
			
	}
	
}



