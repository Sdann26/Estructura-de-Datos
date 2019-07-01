#include <iostream>

using namespace std;
const int n=8; //Aca cambiamos el tamaÃ±o del array

//Realiza la busqueda del elemento mayoria
int busq_EM (int a[n],int b[n]){

	int i=0;
	int j=0;
	int may;

	//Le suma en la cadena al b[i] la cantidad de veces que se repite cada elemento a[i] 	
	for (i=0; i<n; i++){

		for (j=0; j<n; j++){

			if (a[i]==a[j]){

				b[i]++;		

			}								

		}			

	}		
		
	//Halla al que se repitio mas veces
	for (i=0; i<n-1; i++){

		if (b[i]>b[i+1]){

			may=a[i];

		}

		else{

		 	may=a[i+1];

		}			

	}

	//Retorna el valor mas veces repetido
	if (may>n/2){

		return may;

	}

	else {

		return -1;

	}

}

//Imprime la cadena
void imprimir(int a[n]){

	int i;
	
	for (i=0; i<n; i++)
		
		cout<<a[i]<<" ";
		
	cout<<endl; 

}

//Funcion Principal
int main(){

	int pos, i;
	
	int a[n];
	int b[n];

	cout<<"Ingrese los elementos del arreglo: "<<endl;

	for (i=0; i<n; i++){
		
		cout<<"La posicion "<<i+1<<" la ocupara: ";
		cin>>a[i];

	
	}	

	for (i=0; i<n; i++){

		b[i]=0;

	}

	imprimir(a);
	
	pos=busq_EM(a,b);
	
	if(pos==-1){
	
		cout<<"\nNo hay elemento mayoria"<<endl;
		
	}else{
	
		cout<<"\nEl elemento mayoria es "<<pos; 
	
	}
	
}
