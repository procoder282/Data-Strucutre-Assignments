DFS

#include <iostream>
using namespace std;

const int MAX = 10;
int q[MAX];
bool visited[MAX];
int graph[MAX][MAX];

int front=-1,rear=-1;

void enqueue(int x){
    if(rear==MAX-1) {
        cout<<"overflow";
        return;
        
    }
    if(front==-1) front=0;
    q[++rear] = x;
}

int dequeue(){
    if(front==-1 || front>rear){
        cout<<"underflow";
        return -1;
        
    }
    return q[front++];
}

bool isempty(){
    return (front==-1 || front>rear);
}

void DFS(int start, int n){
    
    visited[start] = true;
    cout<<"indexing pages from "<<start<<endl;
    
    
        
        for(int i=0;i<n; i++){
            if(graph[start][i]==1 && !visited[i]){
               DFS(i,n);
            }
        }
    }



int main()
{
    int n,h;
    cout<<"enter no of webpages:";
    cin>>n;
    for(int i=0;i<n;i++){
        visited[i]=false;
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    cout<<"enter no of links:";
    cin>>h;
    cout<<"enter links\n";
    for(int i=0;i<h;i++){
        int a,b;
        cin>>a>>b;
        if(a>=0 && a<n && b>=0 && b<n){
            graph[a][b]=1;
        }else{
            cout<<"invalid...";
        }
    }
    int start;
    cout<<"enter start:";
    cin>>start;
    DFS(start,n);
    return 0;
}
