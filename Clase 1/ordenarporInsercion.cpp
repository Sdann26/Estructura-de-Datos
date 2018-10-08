#include <iostream>
using namespace std;
const int N=8;

//Imprime la cadena
void imprimir(int a[N]){

	int i;
	
	for (i=0; i<N; i++)
		
		cout<<a[i]<<" ";
		
	cout<<endl; 

}

//Algortimo que ordena por inserción
void ordenamientopoInsercion (int a[N]){

	int i, pos, aux;

	for(i=0; i<N; i++){
		
		pos=i;
		
		//Desde la posicion donde esta va ordenando desde esta a los numeros anteriores
		while ((pos>0) && a[pos]<a[pos-1]){
			
			aux=a[pos];
			a[pos]=a[pos-1];
			a[pos-1]=aux;
			
			pos--;
			
		}		
		
	}

}

int main(){
	
	int a[N]={5,1,3,8,7,4,2,6};
	
	cout<<"Array Inicial:"<<endl;
	imprimir (a);
	
	cout<<endl;
	
	ordenamientopoInsercion (a);
	
	cout<<"Array Ordenado:"<<endl;	
	
	imprimir (a);
	
	return 0;
	
}
