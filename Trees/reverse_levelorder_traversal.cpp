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
void ReverselevelOrder(Node* root){
	Node* current;
	queue <Node*> q;
	q.push(root);

	stack <int> s;
	while(!q.empty()){
		current = q.front();
		s.push(current->data);
		if(current->right) q.push(current->right);
		if(current->left) q.push(current->left);
		q.pop();
	}

	while(!s.empty()){
		int temp = s.top();
		cout<<temp<<" ";
		s.pop();
	}

	return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Reverse Level Order traversal"<<endl;
	ReverselevelOrder(root);
    cout<<endl;

	cout<<endl;
	return 0;
}