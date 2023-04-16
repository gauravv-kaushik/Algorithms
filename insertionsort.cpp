#include <iostream>
using namespace std;
int count=0;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        count++;
        int curr=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}

int main(){
    int n;
    cout << "enter no. of elements :";
    cin >> n;
    int arr[n];
    cout << "enter elements :\n";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    insertionSort(arr,n);
    cout << "array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\nno. of comparisions are :" << count;
}