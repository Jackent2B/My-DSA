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

//Reference: vivekandna khyadade
void diagonal_traversal(Node* root){
	Node* current;
	queue <Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		current = q.front();
		q.pop();

		//This if block tells you that the one diagonal is over and a new diagonal is started.
		if(current == NULL){
			q.push(NULL);
			current = q.front();
			q.pop();
			if(current == NULL) break; // it means when we encounters two continues NULL in the queue,
									   // it would mean that we have covered all the diagonals.
		}
		
		while(current != NULL){
			cout<<current->data;
			if(current->left) q.push(current->left);
			current = current->right;
		}
	}
	return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->left->left->left = new Node(9);
	root->left->right = new Node(5);

	diagonal_traversal(root);
	cout<<endl;
	return 0;
}