#include<iostream>
using namespace std;
int V,E;
int parent[100];
int cost [100][100];
int find(int i){
    while(parent[i] != i)
    i = parent[i];
    return i;
}
void union_set(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void kruskal(){
    int mincost=0;
    int edge_count=0;
    while(edge_count<V-1){
        int min=INT_MAX, a=-1, b=-1;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(find(i)!=find(j) && cost[i][j]<min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union_set(a,b);
        cout<<"Edge "<<edge_count++<<" :( "<<a<<" "<<b<<" ) cost: "<<min<<endl;
        mincost+=min;
    }
    cout<<endl;
    cout<<"Total cost of minimum spanning tree: "<<mincost<<endl;
}
int main(){
    cout<<"Enter the no. of vertices: ";
    cin>>V;
    cout<<"\nEnter the no. of edges: ";
    cin>>E;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cost[i][j] = INT_MAX;
        }
    }
    cout<<"\nEnter the source, destination and cost: "<<endl;
    for(int j=0; j<E; j++){
        int m,n;
        cin>>m>>n;
        cin>>cost[m][n];
    }
    for(int i=0; i<V; i++)
        parent[i] = i;
    kruskal();
    return 0;
}