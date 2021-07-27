#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node* left, *right;
};
 
Node* getNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
void solve(Node* root, int sum,int len, int& maxLen, int& maxSum)
{
    if (!root) {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    // recur for left subtree
    solve(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);
 
    // recur for right subtree
    solve(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}
 
int sumOfLongRootToLeafPath(Node* root)
{
    if (!root)
        return 0;
 
    int maxSum = INT_MIN, maxLen = 0;
    solve(root, 0, 0, maxLen, maxSum);
    return maxSum;
}
 
int main()
{
    Node* root = getNode(4);        
    root->left = getNode(2);        
    root->right = getNode(5);        
    root->left->left = getNode(7);   
    root->left->right = getNode(1);  
    root->right->left = getNode(2);  
    root->right->right = getNode(3); 
    root->left->right->left = getNode(6);
    cout << sumOfLongRootToLeafPath(root);
 
    return 0;
}