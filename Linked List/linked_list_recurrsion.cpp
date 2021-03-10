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


////recursion
// void print(Node *it){
// 	if(it == NULL)	return;
// 	cout<<it->data<<" ";
// 	print(it->link);
// }

//print_reverse recursion
void print_reverse(Node *it){
	if(it == NULL)	return;
	print_reverse(it->link);
	cout<<it->data<<" ";
}


int main(){
	head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	print_reverse(head);
	return 0;
}