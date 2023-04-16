#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

int count=0;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void randgen(int arr[],int r){
    srand(time(0));
    int n=rand()%r+1;
    swap(arr,r,n);
}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
        count ++;
    }
    swap(arr,i+1,r);
    return i+1;
}

int quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
	ofstream fout1,fout2;
	fout1.open("comparision.txt");
	fout2.open("output.txt");
	int l=0;
	fout1<<"Size"<<setw(15);
	fout1<<"Comparison"<<endl;
	while(l<100){
	    int size=(rand() %((30-1000+1)+1));
	    int *arr=new int[size];
	    cout<<"Size of the array:: ";
	    cout<<size<<endl;
	    fout2<<"Size::"<<size<<endl;
	    fout2<<"Entered array :: ";
	    for (int i=0;i<size;i++){
		    arr[i]=rand() %((1-200+1)+1);
		    fout2<<arr[i]<<" ";
	    }
        fout2<<endl;
        cout<<"Entered numbers :: "<<endl;
        for (int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        int p= quickSort(arr, 0, size-1);
        fout2<<"Sorted array :: ";
        for (int i=0;i<size;i++){
            fout2<<arr[i]<<" ";
        }
        int c=size*(log(size));
        fout2<<endl;
        cout<<"Total number of comp::"<<c<<endl;
        fout1<<size<<setw(15);
        fout1<<c<<endl;
        
        fout2<<"Comparision::"<<c<<endl;
        fout2<<l++;
    }
	fout1.close();
	fout2.close();
	return 0;
	
}

/*int main(){
    int n;
    cout << "enter no. of elements :";
    cin >> n;
    int arr[n];
    cout << "enter elements :\n";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    randgen(arr,n-1);
    quickSort(arr,0,n-1);
    cout << "array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\nno. of comparisions are :" << count;
}*/