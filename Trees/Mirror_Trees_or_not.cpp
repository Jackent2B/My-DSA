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

bool isMirror(Node* root1, Node* root2){
    if(root1 == NULL && root2==NULL)
        return true;
    if(root1 == NULL || root2==NULL)
        return false;
    if(root1->data == root2->data){
        if(isMirror(root1->left,root2->left) && isMirror(root1->right,root2->right))
            return true;
    }
    return false;
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    
    if(isIdentical(root1,root2))
        cout<<"Identical"<<endl; 
    else
        cout<<"Not Identical "<<endl;
    
    cout<<endl;
    return 0;
}