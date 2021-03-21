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

//Reference :  vivekananda
Node* LCA(Node* root, int p, int q){

		if (root == NULL) 
			return NULL;

		if(root->data==p || root->data==q)
			return root;

		Node* left = LCA(root->left,p,q);
		Node* right = LCA(root->right,p,q);

		if(left != NULL && right!=NULL)
			return root;
		else
			return (left? left: right);
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Lowest Common Ancestor is "<<LCA(root,2,3)->data<<endl;
	
	cout<<endl;
	return 0;
}