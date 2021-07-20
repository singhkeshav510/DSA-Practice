#include<bits/stdc++.h>
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
	Node* top;
	public:
	Stacks(){
		top=nullptr;
	}
	
	void push(int);
	void pop();
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
void Stacks::pop(){
	if(!top)
		cout<<"stack empty\n";
	else{
		cout<<"popped item is" << top->data;
		top=top->link;
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

int main(){
	int n,x;
	Stacks s;
	while(1){
		cout<<"select the operation you want to perform\n1:push\n2:pop\n3:peek\n4:display\n";	
		cin >>n;
		switch(n){
			case 1:{	cout<<"enter the element you want to push\n";
				       	cin>>x;
				       	s.push(x);
			       }
			       		break;
			case 2:s.pop();
			       break;
			case 3:s.peek();
			       break;
			case 4:s.display();
			       break;
			default:cout<<"enter something valid\n";
		}
		char c;
	
		cout<<"do you want to continue\n";
		cin >>c;
		if(c=='n'||c=='N')
			break;
	}
	return 0;
}
