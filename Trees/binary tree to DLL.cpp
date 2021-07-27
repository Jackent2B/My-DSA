#include <bits/stdc++.h>
using namespace std;
// reference : Vivekandan khyadae
// Inorder based approach

// head is initialised as NULL (It will be the head of newly formed DLL)
// p is the root node
void conversion(Node* p, Node* head){
	if(p == NULL)
		return;

	// static is used so that all the changes made to 'prev' pointer
	// will be made in this 'prev' pointer only.
	// No new prev pointer should be made.
	static Node* prev = NULL;
	
	conversion(p->left,head);
	if(prev==NULL){
		head = p;
	}else{
		p->left = prev;
		prev->right = p;
	}
	prev = p;
	conversion(p->right, head);
}