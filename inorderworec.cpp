#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int key;
		Node* left;
		Node* right;
		Node(int data){
			key=data;
			left=nullptr;
			right=nullptr;
		}
};

int main(){
	stack<Node*> s;
	Node* root=new Node(45);
	root->left=new Node(32);
	root->left->left=new Node(25);
	root->left->right=new Node(33);
	root->right=new Node(48);
	Node* current=root;
	while(current!=NULL||!s.empty()){
		while(current!=NULL){
			s.push(current);
			current=current->left;
		}
			current=s.top();
			s.pop();
			cout<<current->key;
			current=current->right;
			
		
	}
}


