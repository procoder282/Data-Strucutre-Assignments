#include <iostream>
#include <string>
using namespace std;

int size;
string *job;
int front=-1,rear=-1;

void enq(string name){
    if ((rear+1)%size==front){
        cout<<"full,,";
        return;
    }else if(front ==-1 && rear==-1){
        front = rear =0;
        job[rear]=name;
    }else{
        rear=(rear+1)%size;
        job[rear]= name;
    }
}
void deq(){
    if(front==-1 && rear==-1){
        cout<<"empty..";
        return;
        
    }
    if(front==rear){   //one element only
        front=rear=-1;
    }
    
    else{
        front= (front+1)%size;
    }
}

void show(){
    int i = front;
    while(i!=rear){
        cout<<job[i]<<"->";
        i=(i+1)%size;
    }
    cout<<job[rear]<<endl;
    
}
int main(){
    int n;
    cout<<"enter max jobs:";
    cin>>n;
    size = n;
    job = new string[size];
    string name1;
    name1="ram";
    enq(name1);
    string name;
    name="sita";
    enq(name);
    string nam;
    nam="sam";
    enq(nam);
    deq();
    show();
    return 0;
}
