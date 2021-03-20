#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

//mirror tree
void mirrorTree(Node* root){

	if(root){
		mirrorTree(root->left);
		mirrorTree(root->right);

		Node* temp = root->left;
		root->left = root->right;
		root->right = root->left;
	}
	return;
}

void printTree(Node* root){
	if(root){
		printTree(root->left);
		cout << root->data << " ";
		printTree(root->right);
	}

}


int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	printTree(root);
	mirrorTree(root);
	cout<<endl;
	printTree(root);
	cout<<endl;
	return 0;
}