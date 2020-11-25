#include <iostream>
#include <math.h>
#include <list>

using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2; 

	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 

		heapify(arr, n, largest); 
	} 
} 

void heapSort(int arr[], int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]); 

		heapify(arr, i, 0); 
	} 
} 

void print(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
}

int dupFind(int arr[], int n) 
{ 

    int j = 0;
    
    list<int> list;
    
    for(int i=0; i<n; i++){
    	
    	if(arr[i]!=arr[i+1]){
    		
    		arr[j] = arr[i];
    		j++;
    		
		}
		else if(!list.contains(arr[i]))
			list.add(arr[i]);
    	
	}
	
	for(int i=0; i<n; i++){
    	
    	cout << list.get[i];
    	
	}
    
} 

int main() 
{ 
	int arr[] = {3, 2, 2, 2, 1, 1, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n);
	
	cout << dupFind(arr, 0, n-1);
	
} 

