#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Reference mycodeschool
bool isBSTUtil(BstNode* root, int minvalue, int maxvalue){
	if(root == NULL)
		return true;

	if(root->data > minvalue 
	  && root->data < maxvalue 
	  && isBST(root->left,minvalue,root->data) 
	  && isBST(root->right,root->data,maxvalue)
	  )
		return true;
	else
		return false;
}

bool isBST(BstNode* root){
	return isBSTUtil(root,INT_MIN, INT_MAX);
}

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

int main() {
	BstNode* root = NULL;
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	cout<<isBST(root);
}