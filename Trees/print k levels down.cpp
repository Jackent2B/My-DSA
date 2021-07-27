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

// Method1: based on level order traversal
void printKLevelNodes(Node* root, int k){

	Node* current;
	queue <Node*> q;
	q.push(root);

	int level = 0;
	while(!q.empty()){
		int n = q.size();
		for (int i = 0; i < n; ++i)
		{
			current = q.front();
			if(level==k )cout<<current->data<<" ";
			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
			q.pop();
		}
		level++;
	}
	return;
}

// Method 2: using recursion
void printKLevelNodes(Node* root, int k){

	if(root == NULL || k<0)
		return;
	if(k==0)
		cout<<root->data<<" ";
	printKLevelNodes(root->left,k-1);
	printKLevelNodes(root->right,k-1);	
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Print K level Nodes"<<endl;
	printKLevelNodes(root,1);
    cout<<endl;

	cout<<endl;
	return 0;
}