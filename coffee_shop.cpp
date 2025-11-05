#include <iostream>
#include <string>
using namespace std;

struct shop {
    string name;
    shop* next;
};

class queue {
private:
    shop* front;
    shop* rear;

public:
    queue() {
        front = rear = NULL;
    }

    void enqueue() {
		string name;
		cout<<"Enter name of customer:";
		cin>>name;
        shop* newnode = new shop();
        newnode->name = name;
        newnode->next = NULL;

        if (rear == NULL) {//empty queue
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        cout<< "\n"<<name<<" is added in queue\n";
    }


    void display() {
        shop* temp = front;
        cout<<"Current line:";
        while (temp != NULL) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    void remove(){
		cout<<front->name<<"'s order is ready. They leave the line.";
		if(front==rear){
			shop* temp=front;
			delete temp;
			front=NULL;
			rear= NULL;
		}else{
			if(rear!=NULL){
				shop* temp=front;
				front=front->next;
				delete temp;
			}
		}
	}
};

int main() {
	int option;
	queue q;
	
	do{
		cout<<"\n--- Coffee Shop Queue Menu ---\n";
		cout << "1 New Customer Arrival (Enqueue)\n";
        cout << "2 Serve Customer (Dequeue)\n";
        cout << "3 Show Queue\n";
        cout << "4  Exit\n";
        cout << "Choose an option: ";
        cin>>option;
        switch(option){
			case 1:
			
			q.enqueue();
			break;
			
			case 2:
			
			q.remove();
			break;
			
			case 3:
			
			q.display();
			break;
			
			case 4:
			cout<<"Exiting the shop.";
			break;
			
			default:
			cout<<"Enter valid choice.\n";
			break;
		}
	}while(option != 4);
			
	
    return 0;
}
