#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    }
};

//Reference : Level Order traversal MY Code School
void levelOrder(Node* root){

	Node* current;
	queue <Node*> q;
	q.push(root);

	while(!q.empty()){
		current = q.front();
		cout<<current->data<<" ";
		if(current->left) q.push(current->left);
		if(current->right) q.push(current->right);
		q.pop();
	}
	return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Level Order traversal"<<endl;
	levelOrder(root);
    cout<<endl;

	cout<<endl;
	return 0;
}