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

// pointer to traverse till end
int start = 0;

Node* binaryTreeToString(string str){

	if(str.length()==0)
		return NULL;

	// To check is the number possitive or negative
	bool isNeg = false;

	if(str[start] == '-'){
		isNeg = true;
		start++;
	}

	//Finding the root element
	int num = 0;
	while(start < str.length() && str[start] >= 48 && str[start]<= 57){
		int digit = str[start] - '0';
		num = num * 10 + digit;
	}

	// if isNeg is true, so converting root element to negative
	if(isNeg)
		num = -1*num;

	Node* root = new Node(num);
	if(start >= str.length())
		return root;

	// for left side
	if(start < str.length() && str[start] == '('){
		start++;
		root->left = binaryTreeToString(str);
	}

	if(start < str.length() && str[start] == ')'){
		start++;
		return root;
	}

	// for right side
	if(start < str.length() && str[start] == '('){
		start++;
		root->right = binaryTreeToString(str);
	}

	if(start < str.length() && str[start] == ')'){
		start++;
		return root;
	}
	
	return root;
}


void preorder(Node* root){
	if(root == NULL)
		return;
	cout<<root->data;
	if(root->left)
		preorder(root->left);
	if(root->right)
		preorder(root->right);
}

int main(){
	string str = "-42(2(3)(1))(6(5))";
	Node* root = binaryTreeToString(str);
	preorder(root);
	return 0;
}
