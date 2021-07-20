#include<iostream>
using namespace std;
class Node{
        public:
        int data;
        Node* link;

        Node(int data){
                link=NULL;
                this->data=data;
        }
};
class Stacks{
	public:
        Node* top;
        
        Stacks(){
                top=nullptr;
        }

        void push(int);
        int pop();
        void peek();
        void display();
};
void Stacks::push(int data){
        Node* temp=new Node(data);
        if(!temp)
                cout<<"heap overflow\n";
        temp->link=top;
        top=temp;
}
int Stacks::pop(){
        int x;
	if(!top)
               return x;
        else{
              x=top->data;
	       	// cout<<"popped item is" << top->data;
                top=top->link;
        	return x;        
	}
}
void Stacks::peek(){
        if(!top)
                cout<<"stack empty\n";
        else {
                cout<<"top most element is "<< top->data<<"\n";
        }
}
void Stacks::display(){
        cout<<"These are elements present in stack\n";
        for(Node* temp=top;temp!=nullptr;temp=temp->link)
                cout<<temp->data<<"\n";
}

