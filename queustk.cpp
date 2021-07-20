#include<iostream>
#include"stackl.h"
using namespace std;
class Queue{
	Stacks s1,s2;
	public:
	void enQueue(int);
	int deQueue();
	void display();
};
void Queue::enQueue(int x){
	while(s2.top!=nullptr)
		s1.push(s2.pop());
	s1.push(x);
}
int Queue::deQueue(){
	int x;
	if(s1.top&&s2.top)
		return -1;
	while(s1.top!=nullptr)
		s2.push(s1.pop());
	x=s2.pop();
	return x;
}
void Queue::display(){
	Stacks s3,s4;
	s3=s2;
	s4=s1;
	int x;
        if(s4.top&&s3.top)
                return;
        while(s4.top!=nullptr)
                s3.push(s4.pop());
     	while(s3.top){		
       		x=s3.pop();
		cout<<x<<" ";
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
                case 2:{int y= q.deQueue();
			       if(y==-1)
				       cout<<"queue empty\n";
			       else 
				       cout<<y<<" is popped from queue\n";
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
