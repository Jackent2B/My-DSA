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

void rightView(Node* root){

    if(root == NULL)
        return;
        
    Node *current;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();

        for(int i=0; i<n;i++){
            current = q.front();
        
            if(i==n-1) cout<<current->data<<" ";    
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
            q.pop();
        }
    }
    return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Right View"<<endl;
	rightView(root);
    cout<<endl;

	cout<<endl;
	return 0;
}