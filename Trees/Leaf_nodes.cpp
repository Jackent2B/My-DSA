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

void LeafNodes(Node* root) 
{ 
    if(root){
        if (!root->left && !root->right)
        {
            cout << root->data << " "; 
            return;
        }
       if (root->left)
           LeafNodes(root->left);
             
        if (root->right)
           LeafNodes(root->right);
    }     
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	LeafNodes(root);
    cout<<endl;

	cout<<endl;
	return 0;
}