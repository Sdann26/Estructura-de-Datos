// Realize una impresion de los valores del grafo de mayor a menor 

#include<iostream>
using namespace std;

struct nodo{
	int nombre;
	char color;
	struct nodo *sgte;
	struct arista *ady;
};

struct arista{
	struct nodo *destino;
	struct arista *sgte;
};

struct Nodo {
	
	int dato;
	Nodo *izq;
	Nodo *der;
	
};

typedef struct nodo *Tnodo;
typedef struct arista *Tarista;
Tnodo p; // El primer nodo
Nodo *arbol = NULL; // El primer arbol para ordenamiento

/* FUNCIONES PARA ARBOL DE BUSQUEDA */

Nodo *crearNodo(int n){
	
	Nodo *nuevo_nodo = new Nodo(); 
	
	nuevo_nodo -> dato = n;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> der = NULL;
	
	return nuevo_nodo;
}

void insertarArbol(Nodo *&arbol, int n){
	
	if (arbol == NULL){ 
		
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
		
	}
	
	else { 
		
		if (n < arbol -> dato){
			
			insertarArbol(arbol -> izq, n); 
			
		}
		
		else{
			
			insertarArbol(arbol -> der, n); 
			
		}
		
	}
	
}

void inOrden(Nodo* arbol){ // Este es un inOrden invertido 
	
	if (arbol == NULL){
		
		return;
		
	}
	
	else{
		
		inOrden(arbol->der);
		cout << arbol->dato << " -> ";
		inOrden(arbol->izq);
		
	}
	
}

/* FUNCIONES PARA GRAFO */

void insertar_nodo(){
	
	Tnodo t, nuevo=new struct nodo;
	
	cout<<"Ingrese el Nodo: ";
	cin>>nuevo->nombre;
	
	nuevo->sgte=NULL;
	nuevo->ady=NULL;
	
	if(p==NULL){
		p=nuevo;
	}
	else{
		t=p;
		while(t->sgte!=NULL){
			
			t=t->sgte;
		}
		t->sgte=nuevo;
	}
}

void agrega_arista(Tnodo &aux,Tnodo &aux2,Tarista &nuevo){
	
	Tarista q;
	if(aux->ady==NULL){
		aux->ady=nuevo;
		nuevo->destino=aux2;
	}
	else{
		q=aux->ady;
		
		while(q->sgte!=NULL){
			q=q->sgte;
		}
		nuevo->destino=aux2;
		q->sgte=nuevo;
	}
}

void insertar_arista(){
	int ini,fin;
	Tarista nuevo=new struct arista;
	Tnodo aux,aux2;
	
	if(p==NULL){
		cout<<"Grafo vacio";
		return;
	}
	
	nuevo->sgte=NULL;
	cout<<"Primer Nodo:";
	cin>>ini;
	cout<<"Segundo Nodo:";
	cin>>fin;
	
	aux=p;
	aux2=p;
	
	while(aux2!=NULL){
	
		if(aux2->nombre==fin)
			break;
		
		aux2=aux2->sgte;
		
	}
	while(aux!=NULL){
		if(aux->nombre==ini){
			agrega_arista(aux,aux2,nuevo);
			return;
		}
		aux=aux->sgte;
	}
}

void mostrar_grafo(){
	
	Tnodo ptr;
	Tarista ar;
	ptr=p;
	cout<<"Nodo / Nodos adyacentes\n";
	
	while(ptr!=NULL){
		cout<<"    "<<ptr->nombre<<"/";
		
		if(ptr->ady!=NULL){
			ar=ptr->ady;
			while(ar!=NULL){
				cout<<" "<<ar->destino->nombre;
				ar=ar->sgte;
			}
		}
		
		ptr=ptr->sgte;
		cout<<endl;
	}
}

void menoraMayor(){

	// Pasaremos por todos los valores del grafo y los insertaremos en un árbol de busqueda y utilizaremos el algoritmo de recorrido inOrden a la inversa

	Tnodo t=p;
	int n;
	while(t->sgte!=NULL){
			n = t->nombre;
			t=t->sgte;
			insertarArbol(arbol, n);
		}

}

int main(void){
	
	p=NULL;
	int opcion;
	
	do{
		cout<<"1.-Insertar Nodo"<<endl;
		cout<<"2.-Insertar Arista"<<endl;
		cout<<"3.-Mostrar Grafo"<<endl;
		cout<<"4.-Mostrar sus valores de mayor a menor"<<endl;
		cout<<"5.-Salir"<<endl;
		cout<<"\nIngrese opcion: ";
		
		cin>>opcion;
		
		switch(opcion){
			case 1: insertar_nodo();
					break;
						
			case 2: insertar_arista();
					break;
			
			case 3: mostrar_grafo();
					break;
					
			case 4: menoraMayor();
							cout <<endl;
							inOrden(arbol);
							cout <<"FIN"<<endl;
					break;
			
			case 5:	break;		
	
			default:cout<<"Opcion Incorrecta!!!";
					break;
		}
		cout<<endl;
		
	}while(opcion!=5);

	return 0;
}

