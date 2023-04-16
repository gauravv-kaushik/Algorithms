#include<iostream>
using namespace std;
void accept(int G[20][20], int n, int e){
    int cost, src, dest;
    cout<<"Enter the source, destination and cost: "<<endl;
    for(int i=0; i<e; i++){
        cin>>src>>dest>>cost;
        G[src][dest] = cost;
        G[dest][src] = cost;
    }
}
void prims(int G[20][20], int n, int e){
    int visited[n], min, total, src, dest;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(G[i][j]==0)
            G[i][j] = 9999;
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    cout<<"\nEnter the source vertex for finding minimum spanning tree: ";
    cin>>src;
    cout<<endl;
    visited[src] = 1;
    total = 0;
    e = 0;
    while(e<n-1){
        min = 9999;
        for(int i=0; i<n; i++){
            if(visited[i]==1){
                for(int j=0;j<n;j++){
                    if(visited[j]!=1){
                        if(min>=G[i][j]){
                            min = G[i][j];
                            src = i;
                            dest = j;
                        }
                    }
                }
            }
        }
        visited[dest] = 1;
        total+=G[src][dest];
        cout<<"EDGE: "<<src<<" to "<<dest<<", COST: "<<min<<endl;
        e++;
    }
    cout<<"\nTotal cost of minimum spanning tree: "<<total;
}
int main(){
    int G[20][20], n, e;
    cout<<"Enter the total number of vertices: ";
    cin>>n;
    cout<<"\nEnter the total number of edges: ";
    cin>>e;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            G[i][j] = 0;
        }
    }
    cout<<endl;
    accept(G,n,e);
    prims(G,n,e);
    return 0;
}