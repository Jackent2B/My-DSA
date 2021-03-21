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

int add(Node* root){

		int sum = 0;
		if (root == NULL) 
			return 0;

		sum = root->data + add(root->left) + add(root->right);
		return sum;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Sum of all nodes"<<add(root)<<endl;
	
	cout<<endl;
	return 0;
}