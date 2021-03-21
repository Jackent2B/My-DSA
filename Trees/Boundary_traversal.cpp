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

void leftView(Node* root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            leftView(root->left);
        }
        else if(root->right){
            cout<<root->data<<" ";
            leftView(root->right);
        }
    }
    return;
}

void rightView(Node* root){
    if(root){
        if(root->right){
            cout<<root->data<<" ";
            rightView(root->right);
        }
        else if(root->left){
            cout<<root->data<<" ";
            rightView(root->left);
        }
    }
    return;
}

void LeafNodes(Node* root) 
{ 
    if(root){
        if (!root->left && !root->right)
        {
            cout << root->data << " "; 
            return;
        }
       if (root->left)
           LeafNodes(root->left);
             
        if (root->right)
           LeafNodes(root->right);
    }     
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    leftView(root);
    rightView(root->right); //we have passed root->right in it so to remove the duplicate of root node
    LeafNodes(root);
    cout<<endl;

    cout<<endl;
    return 0;
}