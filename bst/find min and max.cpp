#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { 
		root = GetNewNode(data);
	}
	
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

void findmin(BstNode* root){
	if(root== NULL){
		cout<<"NULL";
		return;
	}
	 while(root->left != NULL){
	 	root = root->left;
	 }
	 cout<<root->data;
	 return;
}

void findmax(BstNode* root){
	if(root== NULL){
		cout<<"NULL";
		return;
	}
	 while(root->right != NULL){
	 	root = root->right;
	 }
	 cout<<root->data;
	 return;
}

int main() {
	BstNode* root = NULL;
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	findmin(root);
	findmax(root);
}