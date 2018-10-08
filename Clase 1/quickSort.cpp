#include <iostream> 

using namespace std;   

//Funcion para intercambiar valores
void intercambio(int* a, int* b){ 

    int aux = *a; 
    *a = *b; 
    *b = aux; 
    
} 
  
//Realiza el intercambio con el pivote
int partition (int arr[], int low, int high){
 
    int pivote = arr[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++){ 
        
        if (arr[j] <= pivote){ 
        
            i++;    
            intercambio(&arr[i], &arr[j]); 
            
        } 
        
    } 
    
    intercambio(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 


//Funcion quick sort
void quickSort(int arr[], int low, int high){
 
    if (low < high){ 
    
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
        
    } 
} 
  
//Imprime la cadena
void imprimir(int arr[], int size){ 

    int i; 
    for (i=0; i < size; i++){
	
        printf("%d ", arr[i]); 
        
    }
    
} 
  
int main(){
 
    int arr[] = {2, 8, 9, 5, 1, 3, 6, 10, 4,7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
	cout<<"Array inicial:"<<endl;
	
	imprimir(arr, n); 
    
    quickSort(arr, 0, n-1); 
    
	cout<<"\n\nArray Ordenado:"<<endl;
	 
    imprimir(arr, n); 
    return 0; 
} 
