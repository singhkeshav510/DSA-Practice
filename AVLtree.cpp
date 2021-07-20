#include<bits/stdc++.h>//AVL TREE working
using namespace std;
class Node{
	public:
		int data;
		int height;
		Node* left;
		Node* right;
		Node(int key){
			left=nullptr;
			right=nullptr;
			data=key;
			height=0;
		}
};
class AVLtree{
	public:
		Node* root;
		AVLtree(){
			root=nullptr;
		}
		Node* deleteNode(Node*,int);
		Node* insert(Node*,int);
		void inorder(Node*);
		int max(int ,int);
		int getbalance(Node*);
		Node* leftrotate(Node*);
		Node* rightrotate(Node*);
		int height(Node*);
		Node* minValueNode(Node*);
};
Node* AVLtree::leftrotate(Node* node){
	Node *x=node->right;
	Node *y=x->left;
	x->left=node;
	node->right=y;
	return x;
}
Node* AVLtree::rightrotate(Node* node){
        Node *x=node->left;
        Node *y=x->right;
        x->right=node;
        node->left=y;
        return x;
}

int AVLtree::height(Node *s){
	if(s==nullptr)
		return 0;
	else return s->height;
}
int AVLtree::max(int a,int b){
	return (a>b)?a:b;
}
int AVLtree::getbalance(Node* s){
	if(s==nullptr)
		return 0;
	else return height(s->left)-height(s->right);
}
void AVLtree::inorder(Node* s){
	if(s==nullptr)
		return;
	inorder(s->left);
	cout<<s->data<<" ";
	inorder(s->right);
}

Node* AVLtree::insert(Node* root,int data){
	if(root==nullptr)	
		return new Node(data);
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else if(data>root->data){
		root->right=insert(root->right,data);
	}
	else{ return root;
	}
	root->height=1+max(height(root->left),height(root->right));

	int balance=getbalance(root);
	if(balance>1&&data<root->left->data)
		return rightrotate(root);
	if(balance<-1&&data>root->right->data)
		return leftrotate(root);
	if(balance>1&&data>root->left->data){
		root->left=leftrotate(root->left);
		return rightrotate(root);	
	}
	if(balance<-1&&data<root->right->data){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	//unchanged
	return root;
}
Node * AVLtree::minValueNode(Node* node) 
{ 
    Node* current = node; 
     while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
Node* AVLtree::deleteNode(Node* root, int key) 
{ 
       if (root == NULL) return root; 
      if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);  
    else
    { 
        if (root->left == NULL) 
        { 
            Node *temp = root->right; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left; 
            return temp; 
        } 
        Node* temp = minValueNode(root->right); 
         root->data = temp->data; 
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
int main(){
	AVLtree t;//confusion between object creation and normal variable
	while(1){
	cout<<"Select the operation you want to perform\n1:insertion\n2:deletion\n3:inorder display\n";
	int n,data;
	cin>>n;
	switch(n){
		case 1:{
		 		cin>>data;
				t.root=t.insert(t.root,data);
       				break;
		       }
		case 2:{	
				cin>>data;	
			       Node* temp;
				t.root=t.deleteNode(t.root,data);
					cout<<data<<" has been deleted from AVL Tree if present\n";
				
				break;
			}
		case 3:{
			       t.inorder(t.root);
			       break;
		       }
		default:cout<<"enter something valid\n";
		}
	char c;
	cout<<"do you want to continue\n";
	cin>>c;
	if(c=='n'||c=='N'){
		break;
	}
	}

	
	return 0;
 					
}
