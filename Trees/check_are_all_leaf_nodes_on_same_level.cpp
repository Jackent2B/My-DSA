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


bool checkLeafNodesHere(Node* root, int level, int *leafLevel){
    if (root == NULL) return true;
 
    // If a leaf node is encountered
    if (root->left == NULL && root->right == NULL)
    {
        // When a leaf node is found 
        // first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }
 
        // If this is not first leaf node, compare 
        // its level with first leaf's level
        return (level == *leafLevel);
    }
 
    // If this node is not leaf, recursively
    // check left and right subtrees
    return checkLeafNodesHere(root->left, level + 1, leafLevel) &&
            checkLeafNodesHere(root->right, level + 1, leafLevel);
}

bool checkLeafNodes(Node* root){
	int level = 0,leafLevel = 0;
	return checkLeafNodesHere(root,level,&leafLevel);
}


int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Check are all leaf nodes on the same level: "<<checkLeafNodes(root)<<endl;
	
	cout<<endl;
	return 0;
}