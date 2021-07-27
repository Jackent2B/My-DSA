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

// Find node to root path
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

// based on LCA
int distance(Node* root, int num1, int num2){
	
	vector<int> ans1 = findPath(root,num1);
	vector<int> ans2 = findPath(root,num2);

	int i = ans1.size()-1;
	int j = ans2.size()-1;

	while(i >=0 && j>=0 && ans1[i] == ans2[j]){
		i--;
		j--;
	}
    
    i++;
    j++;
	return i+j;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Distance between two nodes "<<distance(root,2,3)<<endl;
	
	cout<<endl;
	return 0;
}