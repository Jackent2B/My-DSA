#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

bool isSubtreeLesser(BstNode* root, int value){
	if(root == NULL)
		return true;
	if(root->data < value 
	  && isSubtreeLesser(root->left,value) 
	  && isSubtreeLesser(root->right, value)
	)
		return true;
	else 
		return false;
}

bool isSubtreeGreater(){
	if(root == NULL)
		return true;
	if(root->data > value 
	  && isSubtreeGreater(root->left,value) 
	  && isSubtreeGreater(root->right, value)
	)
		return true;
	else 
		return false;
}

bool isBST(BstNode* root){
	if(root == NULL)
		return true;

	if(isSubtreeLesser(root->left, root->data) 
	  && isSubtreeGreater(root->right, root->data) 
	  && isBST(root->left) 
	  && isBST(root->right))
		return true;
	else
		return false;
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


}