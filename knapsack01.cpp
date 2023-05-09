#include <iostream>
using namespace std;
int main(){
    int n;
    int profit=0;
    cout << "enter no. of objects : ";
    cin >> n;
    int p[n+1]={0};
    int wt[n+1]={0};
    for(int i=1;i<=n;i++){
        cout << "enter profit of object "<<i<< " and its weight : ";
        cin >> p[i] >> wt[i];
    }
    int m;
    cout << "enter capacity of bucket : ";
    cin >> m;
    int k[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i]<=w){
                k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    cout << "Table for solving Knapsack :\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

    int i=n,j=m;
    cout << "\nObjects filled in bucket are :";
    while(i>0 && j>0){
        if(k[i][j]==k[i-1][j]){
            i--;
        }
        else{
            cout << "object" << i << " ";
            profit+=p[i];
            j=j-wt[i];
            i--;
        }
    }
    cout << "\nprofit = "<<profit;
    cout << "\ncapacity used = "<<m-j;
}
