#include <bits/stdc++.h>
using namespace std;

// Reference : pepcodign

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

vector<int> ans;
bool findPath(Node* root, int num){
	if(root == NULL)
		return false;

	if(root->data == num){
		ans.push_back(root->data);
		return true;
	}

	bool findINLeft = findPath(root->left, num);
	if(findINLeft){
		ans.push_back(root->data);
		return true;
	}

	bool findINRight = findPath(root->right, num);
	if(findINRight){
		ans.push_back(root->data);
		return true;
	}

	return false;
}

int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	if(findPath(root, 5)){
	    for(int i=0; i<ans.size(); i++){
	        cout<<ans[i]<<" ";
	    }
	}
	    ;

	return 0;
}