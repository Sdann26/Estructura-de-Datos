#include<iostream>
using namespace std;
const int N=10;

//Imprime la cadena
void imprimir(int a[N]){

	int i;
	
	for (i=0; i<N; i++)
		
		cout<<a[i]<<" ";
		
	cout<<endl; 

}

//Algortimo que ordena 
void ordenamiento (int a[N]){

	int i, j, aux, min, may;
	
	for (i=0; i<N-1; i++){
	
		min=i/2;
		may=N-(i/2+1);
		
		if ((i+2)%2==0){

			for (j=min+1; j<N-min; j++){
		
				//Busca el indice del minimo
				if (a[j]<a[min]){
			
					min=j;
				
				}
			
			}
		
			//Realiza el cambio del minimo a la posicion que le corresponde
						
			aux=a[min];
			a[min]=a[i/2];
			a[i/2]=aux;
			
			imprimir(a);	
		
			}

		else{

			for (j=min+1; j<N-min; j++){
		
				//Busca el indice del mayor
				if (a[j]>a[may]){
			
					may=j;
				
				}

				
			
			}
		
			//Realiza el cambio del mayor a la posicion que le corresponde
						
			aux=a[may];
			a[may]=a[N-(i/2+1)];
			a[N-(i/2+1)]=aux;
			
			imprimir(a);	
		
			
		}

	}

}


//Funcion Principal
int main(){

	int a[N]={10, 6, 2, 5, 3, 1, 7, 4, 8, 9};
	
	cout<<"Lista Inicial:"<<endl;
	imprimir (a);
	
	cout<<endl;
	
	ordenamiento (a);
	
	cout<<"Lista Ordenada:"<<endl;	
	
	imprimir (a);
	
	return 0;
	
}
