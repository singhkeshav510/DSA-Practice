#include<iostream>
using namespace std;
class Node{
        public:
                int data;
                Node* link;
                Node(int data){
                        link=nullptr;
                        this->data=data;
                }
};
class Queue{
	public:
        Node* rear;
        Node* front;
        
        Queue(){
                rear=nullptr;
                front=nullptr;
        }
        void enQueue(int);
        int deQueue();
        void display();
};
void Queue::enQueue(int x){
        Node* temp=new Node(x);
        if(front==nullptr&&rear==nullptr){
                front=temp;
                rear=temp;
        }
        else
        {       temp->link=rear;
                rear=temp;
        }
}
int Queue::deQueue(){
        Node* iter=NULL;
        iter=rear;
	int x;
        if(front==nullptr&&rear==nullptr)
	{     cout<<"Nothing to remove\n";
		return -1;}
        else{   if(iter==front){
			x=front->data;
                        front=nullptr;
                        rear=nullptr;
                       
        }
	else{
                while(iter!=front)
                        iter=iter->link;
                x=front->data;
                front=iter;}

		return x;
        }
}
void Queue::display(){
        Node* iter=NULL;
        iter=rear;
                                                                                                                                                           
        while(iter!=front->link){																					
                cout<<iter->data<<" ";
                iter=iter->link;        }
        cout<<"\n";
}

