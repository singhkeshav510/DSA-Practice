#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		left=nullptr;
		right=nullptr;
		this->data=data;
	}
};
class Tree{
	public:
	int data;
	Node *root;
	Tree(){
		root=nullptr;
	}
	void insertlevel(int);
	Node* deletion(int);
	void inorder(Node *);
	void deletedeep(Node *);

};
void Tree::insertlevel(int key){
	Node* temp;
	queue<Node*> q;
	if(root==nullptr){
		temp=new Node(key);
		root=temp;
		return;
	}
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(!temp->left){
			temp->left=new Node(key);
			break;
		}
		else {
			q.push(temp->left);
		}
		if(!temp->right){
			temp->right=new Node(key);
			break;
		}
		else {
			q.push(temp->right);
		}
	}
}
void Tree::deletedeep(Node *tem){
        Node* temp;
        queue<Node*> q;
        if(root==nullptr){
            return ;
        }
        q.push(root);

        while(!q.empty()){
                temp=q.front();
                q.pop();
		if (temp == tem) { 
            delete (tem); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == tem) {  
               temp->right=nullptr;
		    	delete (tem);
	       		return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == tem) { 
                temp->left=nullptr;
		    delete (tem); 
		
                return; 
            } 
            else
                q.push(temp->left); 
        } 
        }
}
//need to make queue like this
Node *Tree::deletion(int key){
	Node *temp;
	if(root==nullptr)
		return nullptr;
	if(root->left==nullptr&&root->right==nullptr)
	{
		if(root->data==key)
		{	delete root;
			
		}
		return root;
	}
	queue<Node*> q;
	Node* keynode=nullptr;
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->data==key)
			keynode=temp;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	if(keynode!=nullptr){
		int x=temp->data;
		deletedeep(temp);
		keynode->data=x;
	}
	return root;

	

	
}
void Tree::inorder(Node* root){
	if(root==nullptr)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	int n;
	Tree t;
	while(1){
	cout<<"what operations do you want to perform\n1:insertion\n2:deletion of a node\n3:inorder display\n";
	cin>>n;
	switch(n){
		case 1:{
			       int x;
			       cin >>x;
				t.insertlevel(x);
		       
		       break;
		       }
		case 2:{	Node *temp;
			       int x;
			       cout<<"enter the node value you want to delete\n";
			       cin>>x;
			       temp=t.deletion(x);
			       cout<<"if there,node has been deleted\n";
			       break;
		       }
		case 3:{
			       t.inorder(t.root);
			       break;
		       }
		default:cout<<"enter the valid input\n";
	}
	cout<<"do you want to continue\n";
	char c;
	cin>>c;
	if(c=='n')
		break;
	}
	return 0;
}



	
