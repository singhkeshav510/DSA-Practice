#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next=nullptr;
	}
};
class SLL{
	public:
	Node* head;
	SLL(){
		head=nullptr;
	}
	int midelement();
	void createloop(int);
	int detectcycle();
	void sort();
	void insert(int);
	void deletionatNode(int);
	void enddel();
	void displyns();
	void removeloop();
	void reverse();
	Node* search(int);//search not applied due to mid element
};
void SLL::insert(int x){
	Node* temp=new Node(x);

	if(head==nullptr)
		head=temp;
	else {
		temp->next=head;
		head=temp;
	}
}
void SLL::deletionatNode(int x){
	Node* iter;
	
	if(head->data==x)
		head=head->next;

	else{iter=head;
	while(iter->next){
		
	if(iter->next->data==x&&iter->next!=nullptr){
		iter->next=iter->next->next;
		break;
	}
	iter=iter->next;}
	}
}
void SLL::enddel(){
	Node* iter,*s;
	iter=head;
	s=head;
	if(head){
		while(iter->next){
			s=iter;
			iter=iter->next;
	}
		s->next=nullptr;
	}
}
int SLL::midelement(){
	Node* m,*dm;
	m=head;
	dm=head;
	if(m->next==nullptr)
		return m->data;
	while(dm->next!=nullptr&&dm!=nullptr&&dm->next->next!=nullptr){
		dm=dm->next->next;
		m=m->next;
	}
		return m->data;
}

void SLL::sort(){
	int x=-999;
	Node* temp=new Node(x);
	if(head==nullptr)
		cout<<"no element to sort\n";
	else if(head->next==nullptr)
		return;
	else{
		for(Node* t=head;t->next!=nullptr;t=t->next)
			for(Node* p=t->next;p!=nullptr;p=p->next)
				if(p->data<t->data){
					temp->data=t->data;
					t->data=p->data;
					p->data=temp->data;
				}
	}
}
void SLL::displyns(){
	Node* iter;
	int n=0;
	iter=head;
	
	if(iter==nullptr)
		cout<<"list empty\nsize is"<<n<<"\n";
	else{
		while(iter){
			cout<<iter->data<<" ";
			n++;
			iter=iter->next;
		}
		cout<<"\nsize is "<<n<<"\n";
	}
}
//finding node at which cycle is created
int SLL::detectcycle(){
	Node *sp,*dp,*det;
	sp=head;
	dp=head;
	det=head;
	if(head->next==nullptr){
		cout<<"no loop\n";
		return -1;
	}
	else {
		while(dp!=nullptr&&dp->next!=nullptr&&dp->next->next!=nullptr){
			dp=dp->next->next;
			sp=sp->next;
			if(sp==dp)
			{	if(sp==head)
					return sp->data;
				else{
				while(det->next!=sp->next){
					det=det->next;
					sp=sp->next;
				}
				return det->next->data;
					}
			}
			
		}
	return -1;
	}
}

void SLL::createloop(int x){
	int y=detectcycle();
	if(head->next==nullptr){
		cout<<"loop not possible\n";
	}
	else if(y==-1){
		Node* sp,*dp=new Node(x);
		sp=head;
		dp=head;
		while(sp->next!=nullptr)
			sp=sp->next;
		while(dp->next!=nullptr&&dp->data!=x)
		{
			dp=dp->next;
		}
		if(dp->data==x){
			sp->next=dp;

		}
	}
}
void SLL::removeloop(){//doesnt work
	Node *sp,*dp,*det;
	sp=head;
	dp=head;
	det=head;
	int y=detectcycle();
	if(head->next==nullptr){
                cout<<"loop not possible\n";
        }
	else if(y==-1){
		 while(dp!=nullptr&&dp->next!=nullptr&&dp->next->next!=nullptr){
                        dp=dp->next->next;
                        sp=sp->next;
                        if(sp==dp)
                        {      
                                while(det->next!=sp->next){
                                        det=det->next;
                                        sp=sp->next;
                                }
				sp->next=nullptr;
				return;
                                 
                                        }
                        }

                }
}
void SLL::reverse(){
	Node *p,*s,*d;
	s=head;
	d=nullptr;
	p=nullptr;
	if(s->next==nullptr)
		cout<<"reverse not possible\n";
	else{
		while(s!=nullptr){
			
			d=s->next;
			s->next=p;
			p=s;
			s=d;
		}
		head=p;
	}
}


int main(){
	SLL *s=new SLL();
	int n;
	while(1){
		cout<<"enter the function you want to use\n1:insert\n2:deletenode with value\n3:end delete\n4:midelement\n5:detectcycle\n6:sorting\n7:display list\n8:createloop\n9:removeloop\n10:reverselinklist\n11:searchelement\n";
		cin>>n;
		switch(n){
			case 1:{	int x;
				       cout<<"enter the element you want to insert\n";
				       cin >>x;
				       s->insert(x);
			       }
			       break;
			case 2:{	int x;
				       cout<<"enter the value whose first appearance you wan delete\n";
				       cin>>x;
				       s->deletionatNode(x);
			       }
			       break;
			case 3:{
				       s->enddel();
			       }
			       break;
			case 4:{
				       int x;
				       x=s->midelement();
				       cout<<x<<" is the mid element of list\n";
			       }
			       break;
			case 5:{	int x;
				       x=s->detectcycle();
				       if(x==-1)
					       cout<<"cycle isn't there\n";
				       else cout<<"there is a cycle meeting at "<< x<<"\n";
			       }
			       break;
			case 6:{s->sort();
			       }
			       break;
			case 7:s->displyns();
			       break;
			case 8:{
				       int x;
				       cout<<"enter the element where you want loop\n";
				       cin>>x;
				       s->createloop(x);
			       }
			       break;
			case 9: s->removeloop();
				break;
			case 10:s->reverse();
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



