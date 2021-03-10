#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* link;
};

Node *head;

void insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;

	if(head == NULL){
		head = temp;
		return;
	}

	Node* it = head;
	while(it->link != NULL){
		it = it->link;
	}
	it->link = temp;
	return;
}


//recursion
void print(Node *it){
	if(it == NULL)	return;
	cout<<it->data<<" ";
	print(it->link);
}

//remove duplicates
Node* removeDuplicates(Node *root)
{
 // your code goes here
 if(root == NULL)
    return NULL;
 
 Node* it = root;
 while(it->link != NULL){
     Node* temp = it->link;
     if(it->data == temp->data){
         it->link = temp->link;
         free(temp);
     }else{
         it = it->link;
     }
 }
 return root;
}


int main(){
	head = NULL;
	insert(1);
	insert(2);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	
	cout<<"LL with duplicates : "<<endl;
	print(head);
	cout<<endl;
	Node* ans = removeDuplicates(head);
    cout<<"LL without duplicates : "<<endl;
	print(ans);
	return 0;
}
