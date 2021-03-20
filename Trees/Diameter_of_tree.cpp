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
int FindHeight(Node* root){

		if (root == NULL) 
			return -1;
		//to find no.of nodes in height
		//if (root == NULL) 
		//	return 0;
		int left=FindHeight(root->left);
		int right = FindHeight(root->right);
		return max(left,right)+1;
}


int Diameter(Node* root){

		if (root == NULL) 
			return 0;
		//to find no.of nodes in height
		//if (root == NULL) 
		//	return 0;
		int leftH=FindHeight(root->left);
		int rightH = FindHeight(root->right);
		
		int leftDiameter = Diameter(root->left);
		int rightDiameter = Diameter(root->right);		

		return max((leftH+rightH+1),max(leftDiameter,rightDiameter));
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->left->left->left = new Node(9);
	root->left->right = new Node(5);

	cout<<Diameter(root)<<endl;
	cout<<endl;
	return 0;
}