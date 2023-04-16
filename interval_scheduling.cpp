#include<iostream>
#include<algorithm>
using namespace std;
struct Job{
    int st,ft,w;
};
bool compare(Job j1, Job j2){
    return (j1.ft< j2.ft);
}
int binarySearch(Job jobs[], int index){
    int low = 0, high = index - 1;
    while(low<=high){
        int mid = (low + high)/2;
        if (jobs[mid].ft<=jobs[index].st){
            if (jobs[mid + 1].ft <= jobs[index].st)
            low = mid + 1;
            else
            return mid;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int findMaxProfit(Job arr[], int n){
    sort(arr, arr+n, compare);
    int *table = new int[n];
    table[0] = arr[0].w;
    for(int i=1; i<n; i++){
        int inclWeight = arr[i].w;
        int k = binarySearch(arr, i);
        if (k != -1)
        inclWeight += table[k];
        table[i] = max(inclWeight, table[i-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}
int main(){
    int n;
    int st[n],ft[n],w[n];
    struct Job arr[n];
    cout<<"Enter the no. of jobs: ";
    cin>>n;
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the start time, finish time and weight associated with job: ";
        cin>>arr[i].st;
        cin>>arr[i].ft;
        cin>>arr[i].w;
    }
    cout<<endl;
    cout<<"Optimal Solution is: "<<findMaxProfit(arr,n);
    return 0;
}
