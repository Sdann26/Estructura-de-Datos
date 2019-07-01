#include <iostream>
using namespace std;

//Aca define el tamaaño del arreglo
const int n=3;
const int m=3;

//Imprime la cadena
void imprimira(int a[n]){

	int i;
	
	for (i=0; i<n; i++){
		
		cout<<a[i]<<" ";
	
	}

	cout<<endl; 

}

void imprimirb(int b[]){

	int i;
	
	for (i=0; i<m; i++){
		
		cout<<b[i]<<" ";
	
	}

}

//Funcion principal
int main(){
	
	int a[n]={4, 3, 2};
	int b[m]={1, 6, 5};	

	cout<<"Lista Inicial:"<<endl;
	imprimira (a);
	imprimirb (b);
	
	cout<<endl;
	
	cout<<endl; 
	
	cout<<"Lista Ordenada:"<<endl;	

	int i=0,j= 0;

	int men=9999, aux=9999;

	for (i=0; i<n+m; i++){

		for (j=0; j<n; j++){

			if(a[j]<men){

				men=a[j];
				
			}

		}

		for (j=0; j<m; j++){

			if(b[j]<men){

				men=b[j];

			}

		}

		cout<<men<<" ";

		for (j=0; j<n; j++){

			if(a[j]==men){

				a[j]=aux;
				
			}

		}

		for (j=0; j<m; j++){

			if(b[j]==men){

				b[j]=aux;

			}

		}

		men= 9999;

	}
		
	return 0;
	
}
