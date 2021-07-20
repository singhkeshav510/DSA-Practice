#include<iostream>
#include"quu.h"
using namespace std;
class Stacks{
	Queue q1,q2;
	public:
	void push(int);
	int pop();
	void display();
};
void Stacks::push(int x){
	q1.enQueue(x);
}
//pop not working properly
int Stacks::pop(){
	int x;
	if(q1.front==nullptr)
		return -1;
	else{
	while(q1.rear!=q1.front)
		q2.enQueue(q1.deQueue());
	if(q1.front==q1.rear){
		
		x=(q1.rear)->data;
	}
	Queue temp;
		temp=q1;
		q1=q2;
		q2=temp;
	return x;
}
}
void Stacks::display(){
	Queue q3,q4;
	q3=q1;
	q4=q2;
	int x;
	while(q3.front==nullptr&&q4.front==nullptr){
		while(q3.front!=q3.rear)
                	q4.enQueue(q3.deQueue());
		 if(q3.front==q3.rear){
                	
                	x=q3.rear->data;
        	}
        	Queue temp;
                	temp=q1;
               	 	q1=q2;
                	q2=temp;
		cout<<x<<" ";
	}
	cout <<"\n";
}
int main(){
	int n,y;
	Stacks s;
	while(1){
	cout<<"SELECT THE OPERATION YOU WANT TO WORK WITH\n1:PUSH\n2:POP\n3:DISPLAY\n";
	cin >>n;
	switch(n){
		case 1:{cout<<"enter the element you want to push\n";
		       int x;
			cin >>x;
	 		s.push(x);
		       }
		       break;
		case 2:{int x;
                               x=s.pop();
			       
			       if(x==-1)
			       cout<<"stack empty\n";
		       else{
			      
			       cout<<x<<" is popped from stack\n";
		       }}
		       break;
		case 3:s.display();
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
