
#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node *left, *right;
};
 

struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// choose max from inc and exc
unordered_map<Node*, int> mp;
int getMaxSum(Node* root){
    if(root == NULL)
        return 0;

    if(mp.find(root) != mp.end())
        return mp[root];

    int inc = root->data;
    if(root->left){
        inc += getMaxSum(root->left->left);
        inc += getMaxSum(root->left->right);
    }
    if(root->right){
        inc += getMaxSum(root->right->left);
        inc += getMaxSum(root->right->right);   
    }

    int exc = getMaxSum(root->left) + getMaxSum(root->right);
    return mp[root] = max(inc,exc);
}
 
int main()
{
    mp.clear();
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
 
    cout << getMaxSum(root) << endl;
    return 0;
}