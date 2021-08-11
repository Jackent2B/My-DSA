#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
int sum = 0;
stack<int> st;

void printstack(){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void printKPathSolve(Node *root, int k)
{   
    if(root==NULL)
        return;
    sum = sum + root->data;
    st.push(root->data);
    if(sum==k){
        printstack();
    }

    printKPathSolve(root->left,k);
    printKPathSolve(root->right,k);
    sum = sum - root->data;
    st.pop();   
}

void preorder(Node *root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
 
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    preorder(root);
    
    int k = 9;
    printKPathSolve(root, k);
 
    return 0;
}