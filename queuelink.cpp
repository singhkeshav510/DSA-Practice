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
	Node* rear;
	Node* front;
	public:
	Queue(){
		rear=nullptr;
		front=nullptr;
	}
	void enQueue(int);
	void deQueue();
	void display();
};
void Queue::enQueue(int x){
	Node* temp=new Node(x);
	if(front==nullptr&&rear==nullptr){
		front=temp;
		rear=temp;
	}
	else
	{	temp->link=rear;
		rear=temp;
	}	
}
void Queue::deQueue(){
	Node* iter=NULL;
	iter=rear;
	if(front==nullptr&&rear==nullptr)
		cout<<"Nothing to remove\n";
	else{	if(iter==front){
			front=nullptr;
			rear=nullptr;
			return;
	}
		while(iter!=front)
			iter=iter->link;
		cout<<"dequeued item is" <<front->data<<"\n";
		front=iter;
	}
}
void Queue::display(){
	Node* iter=NULL;
	iter=rear;
	while(iter!=front->link){
		cout<<iter->data<<" ";
		iter=iter->link;
	}
	cout<<"\n";
}
	
int main(){
	int n,x;
	Queue q;
	while(1){
	cout<<"SELECT THE OPERATION YOU WANT TO PERFORM\n1:enqueue\n2:dequeue\n3:display\n";
	cin >>n;
	switch(n){
		case 1:{
			       cout<<"enter the element you want to eneque\n";
			       cin>>x;
			       q.enQueue(x);
		       }
		       break;
		case 2:{
			       q.deQueue();
		       }
		       break;
		case 3:q.display();
		       break;
		default:cout<<"enter something valid\n";
	}
	char c;
	cout<<"do you want to continue\n";
	cin>>c;
	if(c=='n'||c=='N')
		break;
	}
	return 0;
}
