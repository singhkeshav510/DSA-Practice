#include<bits/stdc++.h>
using namespace std;
//using array
class Stack{
	int top;
	int size;
	int* arr=nullptr;
	public:
	Stack(int capacity){
		top=-1;
		size=capacity;
		arr=new int[capacity];
	}

	void push(int);
	void pop();
	bool isEmpty();
	bool isFull();
	void peek();
};
bool Stack::isEmpty(){
	if(top==-1)
		return true;
	else 
		return false;
}
bool Stack::isFull(){
	if(top+1==size)
		return true;
	else 
		return false;
}
void Stack::push(int x){
	if(isFull())
		cout<<"stack overflow\n";
	else{	
		top=top+1;
		arr[top]=x;
	 	}
}
void Stack::pop(){
	if(isEmpty())
		cout<<"stack underflow\n";
	else{
		 cout<<"popped number is" << arr[top]<<"\n";
		 top=top-1;
		}
}
void Stack::peek(){
	cout<<"top element is "<<arr[top]<<"with "<<top<<"\n";
}



class Queue{
        int front;
        int rear;
        int size;
        int *arr=nullptr;
        public:
        Queue(int capacity){
                front=-1;
                rear=-1;
                size=capacity;
                arr=new int[capacity];
        }
        void enQueue(int);
        void deQueue();
        bool isEmpty();
        bool isFull();
};
bool Queue::isFull(){
        if((rear+1)%size==front)
                return true;
        else return false;
}
bool Queue::isEmpty(){
        if(front==-1)
                return true;
        else return false;
}

void Queue::enQueue(int x){
        if((rear+1)%size==front)
                cout<<"Queue full";
        else{
                if(front==-1&&rear==-1)
                {
                        front=0;
                        rear=0;
                }
                else
                        rear=(rear+1)%size;
                arr[rear]=x;
        }
}
void Queue::deQueue(){
        if(front==-1)
                cout<<"Queue empty";
        else{   cout<<"Dequeued element is " << arr[front] <<"\n";
                if(rear==front){
                        rear=-1;
                        front=-1;
                }
                else
			                        front=(front+1)%size;
        }
}
void stacks(){
        int n,t,x;
        cout<<"How many elements you want to place in stack\n";
        cin>>n;
        Stack s(n);
        while(1){
                cout<<"Select what you want to do\n1.PUSH\n2.POP\n3.PEEK\n";
                cin >>t;
                switch(t){
                        case 1:{if(!s.isFull()){
                                for(int i=0;i<n;i++)
                                {cout<<"enter the number\n";
                                cin>>x;
                                s.push(x);}}
                                break;
                               }
                        case 2: {
                                s.pop();
                                break;
                                }
                        case 3:{if(!s.isEmpty()){
                                s.peek();}
                                break;
                                }
                        default:{
                                cout<< "enter some valid point\n";
                                }
                        }
                cout<<"Do you want to continue\n";
                char y;
                cin>>y;
                if(y=='n'||y=='N')
                        break;
                }

}


void quue(){
        int n,t,x;
        cout<<"How many elements you want in queue\n";
        cin >> n;
        Queue q(n);
        while(1){

                cout<<"Operations to be performed:\n1:Enqueue\n2:Dequeue\n";
                cin >>t;
                switch(t){
                        case 1:{
                                       for(int i=0;i<n;i++){
                                                cout<<"enter the element you want to have in queue\n";
                                                cin>>x;
                                                 q.enQueue(x);}
                               }
                                break;
                        case 2:{

                                               q.deQueue();
                                       }
                                       break;
                        default:cout<<"enter something valid\n";
                }
                char x;
                cout<<"do you want to continue\n";
                cin>>x;
                if(x=='n'||x=='N')
                        break;
                }
       
}
int main(){
	int i;
	cout<<"SELECT OPTION YOU WANT TO WORK WITH\n1:stack\n2:queue\n";
	cin >>i;
	switch(i){
		case 1:stacks();
		       break;
		case 2:quue();
		       break;
		default:cout<<"select something valid\n";
	}
}
	
