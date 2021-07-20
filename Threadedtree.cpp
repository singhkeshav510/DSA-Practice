#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		bool lt;
		bool rt;
		Node(int key){
			data=key;
			left=NULL;
			right=NULL;
			lt=true;
			rt=true;
		}
};
Node* inordersuccess(Node* root){
	 if (root -> rt == true) 
        return root->right;  
    root = root -> right; 
    while (root -> lt == false) 
        root = root -> left; 
    return root; 
	

}
Node* leftmost(Node* root){
	Node* cur=root;
	while(cur->lt==false)
		cur=cur->left;
	return cur;
}
void inorder(Node* root){
	if(root==nullptr)
		cout<<"no element\n";
	Node* p=leftmost(root);
	while(p!=nullptr){
		cout<<p->data<<"\n";
		p=inordersuccess(p);

}
}

Node* insertion(Node* root,int t){
	Node* p=root;
	Node* q=NULL;
	while(p!=NULL){
		if(t==p->data){
			cout<<"duplicate keys\n";
			return root;
		}
		q=p;
		if(t<p->data){
			if(p->lt==false){
				p=p->left;
			}
			else break;
		}
		else {
			if(p->rt==false){
				p=p->right;
			}
			else break;
		}
	}
	Node* temp=new Node(t);
	if(q==NULL){
		root=temp;
	}
	else if(t<q->data){
		temp->left=q->left;
		temp->right=q;
		q->left=temp;
		
		q->lt=false;
	}
	else{
		temp->left=p;
		temp->right=q->right;
		
		q->right=temp;
                
                q->rt=false;
	}
	return root;
}


Node* deletion(Node* root,int t){}

int main(){
	int n;
	Node* root=NULL;
	while(1){
		cout<<"SELECT THE OP YOU WANT TO PERFORM\n1.INSERT\n2.DELETE\n3.INORDER\n";
		cin>>n;
		switch(n){
			case 1:{
				       int t;
				       cout<<"enter the number you want to insert\n";
				       cin>>t;
				       root=insertion(root,t);
				       cout<<root->data;
				       break;
			       }
			case 2:{
				       int t;
				       cout<<"enter the number you wanna delete\n";
				       cin >>t;
				       root=deletion(root,t);
				       cout<<"if present, number is deleted\n";
				       break;
			       }
			case 3:{
				       inorder(root);
				       break;
			       }
			default:cout<<"enter proper input\n";
		}
		char c;
		cout<<"do you wanna continue\ny or n\n";
		cin>>c;
		if(c=='n')
			break;
	}
}
