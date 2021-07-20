#include<bits/stdc++.h>
using namespace std;
class Node{
        public:
        int key;
        Node* left;
        Node* right;
        Node(int key){
                this->key=key;
                left=nullptr;
                right=nullptr;
        }
};
class Solution {
    public:
  		Node* insertNode(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->key) {
                    cur = insertNode(root->left, data);
                    root->left = cur;
                } else {
                    cur = insertNode(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
};
void preOrder(Node* root){

        if(root==nullptr)
                return;
        else{
              cout<< root->key<<" ";
	      	preOrder(root->left);
                preOrder(root->right);
                }
}
void inOrder(Node* root){

        if(root==nullptr)
                return;
        else{
                inOrder(root->left);
                cout<< root->key<<" ";
                inOrder(root->right);
                }
}

void postOrder(Node* root){

        if(root==nullptr)
                return;
        else{
                postOrder(root->left);
                postOrder(root->right);
		  cout<< root->key<<" ";

                }
}
int max(int a,int b){
	return (a>b)?a:b;
}
int heightTree(Node* root){
	int ls,rs;
	if(root==NULL)
		return 0;
	else{
		ls=heightTree(root->left);
		rs=heightTree(root->right);
		return 1+max(ls,rs);
	}
}
int sizeTree(Node* root){
	int ls,rs;
	if(root==NULL)
		return 0;
	else{
		ls=sizeTree(root->left);
		rs=sizeTree(root->right);
		return 1+ls+rs;
	}
}
int c=0;
Node* minNode(Node* root){
	if(root==nullptr)
		return NULL;
	else if(root&&root->left==nullptr)
		return root;
	else{
		Node* cur;	
		if(c==0){
		
			cur=minNode(root->left);
		c++;	
		}
	
	return cur;
	}
}
int main(){
        int n,data,x;
        Solution mytree;
	Node* root=nullptr;
        cout<< "How many elements you want tree to be inserted\n";
        cin >> n;
        for(int i=0;i<n;i++)
        {       cin >> data;
                root=mytree.insertNode(root,data);
        }
	cout<<"preorder Traversal\n";
      preOrder(root);
      cout<<"\n";
	cout<<"Inorder Traversal\n";
       inOrder(root);
       cout<<"\n";

	cout<<"postorder Traversal\n";
      postOrder(root);
      cout<<"\n";
	cout<< "Size of Tree is\n";
	x=sizeTree(root);
	cout<<x<<"\n";
	cout<<"Height of Tree:\n";
	x=heightTree(root);
	cout<<x<<"\n";
	cout<<"Node with minimum value\n";
	Node* min=nullptr;
	min=minNode(root);
	cout<<min->key<<"\n";
	cout<<c<<"\n";

        return 0;
}
