#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int key){
        this->left=nullptr;
        this->right=nullptr;
        this->data=key;
    }
};
class Tree{
    public:
    int data;
    Node* root;
    Tree(){
        root=nullptr;
    }
    
        void insert(int);
        Node* deleteit(int);
        void search(int);
        void inorder();
        void deletedeep(Node*);
};
void Tree::insert(int n){
    Node* temp;
	queue<Node*> q;
	if(root==nullptr){
		temp=new Node(n);
		root=temp;
		return;
	}
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(!temp->left){
			temp->left=new Node(n);
			break;
		}
		else {
			q.push(temp->left);
		}
		if(!temp->right){
			temp->right=new Node(n);
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
Node* Tree::deleteit(int key){
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
void Tree::inorder(){
    Node *curr,*prev;
    if(root==nullptr){
        cout<<"No Nodes present\n";
        return;
    }
    curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    
    else {
        prev=curr->left;
        while(prev->right!=nullptr&&prev->right!=curr){
            prev=prev->right;
        }
        if(prev->right==nullptr){
            prev->right=curr;
            curr=curr->left;
        }
        else{
            prev->right=nullptr;
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    }
    cout<<"\n";
}
void Tree::search(int n){

}
int main(){
    int n;
    Tree t;
    while(1){
        cout<<"Enter the operation you want to perform \n1. Insert\n2. Delete \n3. Inorder Traversal\n4. Search\n";
        cin>>n;
        switch(n){
            case 1:{
                cout<<"Enter the number you want to insert\n";
                cin>>n;
                t.insert(n);
                break;
            }
            case 2:{
                Node *temp;
                cout<<"Enter the number you want to delete at first occurence if present\n";
                cin>>n;
                temp=t.deleteit(n);
                break;
            }
            case 3:{
                cout<<"Inorder Traversal:\n";
                t.inorder();
                break;
            }
            case 4:{
                cout<<"Enter the number you want to search for if present\n";
                cin>>n;
                t.search(n);
                break;
            }
            default:{
                cout<<"Enter the valid input\n";
            }
        }
        char c;
        cout<<"Do you want to continue or stop\n";
        cin>>c;
        if(c=='n'||c=='N'){
            break;
        }
    }
}