#include <bits/stdc++.h>
using namespace std;

struct node{
	int data; //4 bytes
	node* link; //4 bytes
};

node* head;

void insert(int num){

	node* temp = new node();
	temp->data = num;
	temp -> link = NULL;
	
	node* it = head;

	if(head == NULL){
		head = temp;
		return;
	}
		
	while(it->link != NULL){
		it = it->link;
	}

	it->link = temp;
	return;
}

void print(){
	node* it = head; 
	while(it->link != NULL){
		cout<<it->data<<" ";
		it=it->link;
	}
	cout<<it->data<<endl;
	return;
}

void reverse(){
	node *prev, *current, *next;
	current = head;
	prev = NULL;

	while(current != NULL){
		next = current->link;
		current->link = prev;
		prev = current;
		current=next; 
	}
	head = prev;
}


/* Recurssion */
// Node* reverse(Node* node)
// {
//     if (node == NULL)
//         return NULL;
//     if (node->next == NULL) {
//         head = node;
//         return node;
//     }
//     Node* node1 = reverse(node->next);
//     node1->next = node;
//     node->next = NULL;
//     return node;
// }

int main(){
    head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	print();
	reverse();
	print();
	return 0;
}