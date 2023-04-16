#include<iostream>
using namespace std;
int knapSack(int v[], int w[], int n, int W){
    int K[n+1][W+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){
                K[i][j] = 0;
            }
            else if(w[i-1]<=j){
                int a = v[i-1] + K[i-1][j - w[i-1]];
                int b = K[i-1][j];
                K[i][j] = (a>b?a:b);
            }
            else{
                K[i][j] = K[i-1][j];
            }
        }
    }
    cout<<"Maximum Value: "<<K[n][W]<<endl;
    cout<<endl;
    cout<<"Selected Items: "<<endl;
    while(n!=0){
        if(K[n][W]!=K[n-1][W]){
            cout<<"Package "<<n<<" with W = "<<w[n-1]<<" and Value ="<<v[n-1]<<endl;
            W = W - w[n-1];
        }
        n--;
    }
}
int main(){
    int n,W;
    cout<<"Enter the no. of items: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the capacity weight: ";
    cin>>W;
    cout<<endl;
    int p[n],w[n];
    cout<<"Enter the value/profit associated with the items: ";
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    cout<<endl;
    cout<<"Enter the weights associated with the each item: ";
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    cout<<endl;
    knapSack(p, w, n, W);
    return 0;
}