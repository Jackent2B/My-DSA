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
 
void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
void printKPathSolve(Node *root, vector<int>& path,int k)
{

    if (!root)
        return;
 
    path.push_back(root->data);
    
    printKPathSolve(root->left, path, k);
    printKPathSolve(root->right, path, k);
 
    /*Check if there's any k sum path that
    terminates at this node
    Traverse the entire path as
    there can be negative elements too*/
    int sum = 0;
    for (int i = path.size()-1; i>=0; i--)
    {
        sum += path[j];
 
        // If path sum is k, print the path
        if (sum == k)
            printVector(path, i);
    }
 
    // Remove the current element from the path
    path.pop_back();
}
 
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathSolve(root, path, k);
}
 
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    printKPath(root, k);
 
    return 0;
}