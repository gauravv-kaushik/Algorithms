#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n){
	vector<float> b[n];

	//Put array elements in different buckets
	for (int i=0;i<n;i++) {
		int bi=n*arr[i];
		b[bi].push_back(arr[i]);
	}

	//Sort individual buckets
	for (int i=0;i<n;i++)
		sort(b[i].begin(),b[i].end());

	//Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}


int main(){
	int n;
	cout << "enter  no. of element :";
    cin >> n;
    float arr[n];
    cout << "enter elements...";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bucketSort(arr, n);  
    cout<<"\nArray after Bucket sort :";  
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
