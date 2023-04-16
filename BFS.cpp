#include <iostream>
using namespace std;
class Qnode{
    public:
    int info;
    Qnode *next;
    Qnode(){
        next=0;
    }
    Qnode(int x,Qnode *n=0){
        info=x;
        next=n;
    }
};
class Queue{
    Qnode *front,*rear;
    public:
    Queue(){
        front=rear=0;
    }
    int isempty();
    void enqueue(int);
    int dequeue();
};
int Queue :: isempty(){
    if(front==0)
    return 1;
    else
    return 0;
}
void Queue :: enqueue(int a){
    Qnode *p=new Qnode(a);
    if(isempty()){
        front=rear=p;
    }
    else{
        rear->next=p;
        rear=p;
    }
}
int Queue :: dequeue(){
    int x=front->info;
    if(rear==front){
        delete front;
        rear=front=0;
    }
    else{
        Qnode *temp;
        temp=front;
        front=front->next;
        delete temp;
    }
    return x;
}
class Graph{
    int v;
    int V[10];
    int M[20][20];
    public:
    void input();
    void breadthFirst(int);
};
void Graph :: input(){
    cout<<"Enter the number of vertices in the graph"<<endl;
    cin>>v;
    cout<<"Enter the vertex in the graph"<<endl;
    for(int i=0;i<v;i++){
        cin>>V[i];
    }
    cout<<"Press 1 if a edge is present else zero"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<"IS THERE A EDGE BETWEEN "<<V[i]<<","<<V[j]<<" IN THE GRAPH?"<<endl;
            cin>>M[i][j];
        }
    }
}
void Graph :: breadthFirst(int x){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    Queue q;
    q.enqueue(x);
    while(!q.isempty()){
        int s=q.dequeue();
        if(!visited[s]){
            visited[s]=true;
            cout<<V[s]<<" ";
            for(int i=0;i<v;i++){
                if(M[s][i]>0 && !visited[i])
                    q.enqueue(i);
            }
        }
    }
}
int main()
{
Graph g;
int start;
g.input();
cout<<"Enter the index of source vertex: ";
cin>>start;
cout<<"Breadth First Traversal for the Graph : ";
g.breadthFirst(start);
return 0;
}
