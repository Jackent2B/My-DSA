#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		this->data = x;
		left = right = NULL;
	}
}

//Reference: Vivekanda Khyade spriral order
void zigZag(Node* root){

	stack <Node*> s1;
	stack <Node*> s2;

	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){	
			Node* current1 = s1.top();
			cout<<current1->data<<" ";
			s1.pop();
			if(current1->left) s2.push(current1->left);
			if(current1->right) s2.push(current1->right);
		}

		while(!s2.empty()){	
			Node* current2 = s2.top();
			cout<<current2->data<<" ";
			s2.pop();
			if(current2->right) s1.push(current2->right);
			if(current2->left) s1.push(current2->left);
		}	
	} 
	return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	zigZag(root);
	return 0;
}