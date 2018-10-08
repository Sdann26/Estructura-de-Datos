#include<iostream>
using namespace std;
const int N=8;

//Imprime la cadena
void imprimir(int a[N]){

	int i;
	
	for (i=0; i<N; i++)
		
		cout<<a[i]<<" ";
		
	cout<<endl; 

}

//Algortimo que ordena por seleccion
void ordenamientoporSeleccion (int a[N]){

	int i, j, aux, min;
	
	for (i=0; i<N-1; i++){
	
		min=i;
		
		for (j=i+1; j<N; j++){
		
			//Busca elindice del minimo
			if (a[j]<a[min]){
			
				min=j;
				
			}
			
		}
		
		//Realiza el cambio del minimo a la poscion que le corresponde
		if (i!=min){
			
				aux=a[min];
				a[min]=a[i];
				a[i]=aux;
			
				imprimir(a);	
		
		}
		
	}

}


//Funcion Principal
int main(){

	int a[N]={5,1,3,8,7,4,2,6};
	
	cout<<"Lista Inicial:"<<endl;
	imprimir (a);
	
	cout<<endl;
	
	ordenamientoporSeleccion (a);
	
	cout<<"Lista Ordenada:"<<endl;	
	
	imprimir (a);
	
	return 0;
	
}
