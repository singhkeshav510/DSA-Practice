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

void inOrder(Node* root){

	if(root==nullptr)
		return;
	else{
		inOrder(root->left);
		cout<< root->key<<" ";
		inOrder(root->right);
		}
}
Node* insertNode(Node* root,int data){
	if(root==nullptr)
		return new Node(data);
	else{
		Node* cur;
                if(data <= root->key)
                   root->left=insertNode(root->left, data);
                 else 
                    root->right=insertNode(root->right, data);
		}
}
int main(){
	int n,data;
	Node* root=nullptr;
	cout<< "How many elements you want tree to be inserted\n";
	cin >> n;
	for(int i=0;i<n;i++)
	{	cin >> data;
		root=insertNode(root,data);
	}
	
	inOrder(root);
	return 0;
}


