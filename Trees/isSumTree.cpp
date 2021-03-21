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

int add(Node* root){

		int sum = 0;
		if (root == NULL) 
			return 0;

		sum = root->data + add(root->left) + add(root->right);
		return sum;
}

bool isSumTree(Node* root)
{
     // Your code here
    if(root == NULL)
        return 1;
    
    if(root->left == NULL && root->right==NULL)
        return 1;
    
    int leftSum = add(root->left);
    int rightSum = add(root->right);
    
    if(root->data == (leftSum+rightSum)){
        if(isSumTree(root->left) && isSumTree(root->right)){
            return 1;
        }
    }
    return 0;    
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Is sum Tree"<<isSumTree(root)<<endl;
	
	cout<<endl;
	return 0;
}