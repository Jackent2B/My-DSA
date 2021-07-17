/*
Following is a 3 step solution for converting Binary tree to Binary Search Tree.
1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
2) Sort the temp array arr[]. 
3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. 
This step takes O(n) time.
*/