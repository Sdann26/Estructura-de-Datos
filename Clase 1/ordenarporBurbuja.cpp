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

//Algortimo que ordena por método burbuja y lo ordenara de forma ascendente
void ordenamientoporMB (int a[N]){

	int i, j, aux;

	for(i=0; i<N; i++){
		
		for(j=0; j<N-1; j++){
			
			if(a[j+1]<a[j]){
				
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
				
			}
			
		}
		
		
	}

}

int main(){
	
	int a[N]={5,1,3,8,7,4,2,6};
	
	cout<<"Lista Inicial:"<<endl;
	imprimir (a);
	
	cout<<endl;
	
	ordenamientoporMB (a);
	
	cout<<"Lista Ordenada:"<<endl;	
	
	imprimir (a);
	
	return 0;
	
}
