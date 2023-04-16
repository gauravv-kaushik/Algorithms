#include<iostream>
#include<cstdlib>
using namespace std;

void heapify(int arr[],int n,int i,int& count){ 
    int largest=i; 
    int l=2*i+1; 
    int r=2*i+2; 
    if (l<n && arr[l]>arr[largest]){ 
        count++;
        largest=l; 
    }
    if(r<n && arr[r]>arr[largest]){
		count++;
    	largest = r;
	}
    if(largest!=i){ 
        swap(arr[i],arr[largest]); 
        heapify(arr,n,largest,count); 
    } 
} 

void heapSort(int arr[], int n,int& count){ 
    for(int i=n/2-1;i>=0;i--) 
        heapify(arr, n, i,count); 
  
    for(int i=n-1;i>0;i--){ 
        swap(arr[0],arr[i]); 
        heapify(arr,i,0,count); 
    } 
} 

int main(){
    int n;
    int count=0;
    cout << "enter no. of elements :";
    cin >> n;
    int arr[n];
    cout << "enter elements :\n";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    heapSort(arr,n,count);
    cout << "array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\nno. of comparisions are :" << count;
}
/*int main(){
	
    int count=0;
    
    for (int i=0;i<100;i++) {
    	
        int size=30+rand()%1000;
        int arr[size];
        for(int j=0;j<size;j++){
            arr[i]=10+rand()%500;
        }
        heapSort(arr,size,count);
        cout<<size<<"#"<<count<<endl;
        count=0;
    }
}*/
