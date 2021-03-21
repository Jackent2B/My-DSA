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

int sumTree(Node* root){

		if (root == NULL) 
			return 0;
		int old_value = root->data;
		int left = sumTree(root->left);
		int right = sumTree(root->right);
		root->data = left + right;
		return root->data + old_value;
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	preorder(root);
	cout<<endl;
	sumTree(root);
	cout<<"sumTree: "<<endl;
	preorder(root);
	cout<<endl;
	return 0;
}