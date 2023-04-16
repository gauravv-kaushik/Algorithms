#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <cstdlib>

using namespace std;
int count=0;
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
        count++;
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

int mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
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
        int p= mergeSort(arr, 0, size-1);
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
    mergeSort(arr,0,n-1);
    cout << "array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\nno. of comparisions are :" << count;
}*/
