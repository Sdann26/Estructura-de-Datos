#include <iostream>
#include<stdlib.h> 
  
using namespace std; 

//Funcion que se encarga de realizar la union de cadenas
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  	
  	//Rellena las 2 nuevas cadenas
    for (i = 0; i < n1; i++){
        
        L[i] = arr[l + i]; 
    
    }
    
    for (j = 0; j < n2; j++){
        
        R[j] = arr[m + 1+ j]; 
        
    }
  
    i = 0; //Indice inicial para el primer subarray 
    j = 0; //Indice inicial para el segundo subarray 
    k = l; //Indice inicial para el subarray de union
    
    
    //Compara los primeros elementos de cada cadena y luego comienza a unirlos en el array principal
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
//Funcion MergeSort
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
    
        int m = l+(r-l)/2; 
        
        //Dividira el analisis de la cadena en cadenas de una sola unidad para analizarlas e ir uniendolas en la funcion merge(unir)
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        //Realiza la acción de unir cadenas
        merge(arr, l, m, r); 
    } 
} 
  

//Funcion para imprimir
void Imprimir(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
//Funcion Principal
int main() 
{ 
    int arr[] = {10, 3 ,2 ,8 ,7 , 12 ,5 ,4 ,20 ,13}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    cout<<"La cadena de elementos es:"<<endl; 
    Imprimir(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    cout<<"\nLa cadena ordenada es:"<<endl; 
    Imprimir(arr, arr_size); 
    return 0; 
} 
