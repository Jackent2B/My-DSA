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

//Reference :  MY Code School
int Height(Node* root){

		if (root == NULL) 
			return -1;

		//to find no.of nodes in height
		//if (root == NULL) 
		//	return 0;

		int left=FindHeight(root->left);
		int right = FindHeight(root->right);
		return max(left,right)+1;
}

bool isBalanced(Node* root){
	if(root==NULL)
		return 1;

	int left = Height(root->left);
	int right = Height(root->right);

	if(abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->left->left->left = new Node(9);
	root->left->right = new Node(5);

	if(isBalanced(root))
		cout<<"Balanced";
	else
		cout<<"Not Balanced";
	
	cout<<endl;
	return 0;
}