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

vector<int> findPath(Node* root, int num){
    vector<int> nullvc;
	if(root == NULL){
	    return nullvc;   
	}

	if(root->data == num){
		vector<int> ans;
		ans.push_back(root->data);
		return ans;
	}

	if(root->left){
		vector<int> temp1 = findPath(root->left, num);
		if(temp1.size()>0){
			temp1.push_back(root->data);
			return temp1;
		}
	}

	if(root->right){
		vector<int> temp2 = findPath(root->right, num);
		if(temp2.size()>0){
			temp2.push_back(root->data);
			return temp2;
		}
	}
	return nullvc;
}

int KthAncestor(Node* root, int num, int k){
	
	vector<int> ans = findPath(root,num);
	return ans[k];
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	int k = 2;
	cout<<"Kth Ancestor is "<<KthAncestor(root,4,k)<<endl;
	
	cout<<endl;
	return 0;
}
