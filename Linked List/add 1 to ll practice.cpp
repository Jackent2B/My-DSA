#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};
Node* head;

void insert(int num){
	Node* newnode = new Node();
	newnode->data = num;
	newnode->next = NULL;

	if(head == NULL){
		head = newnode;
		return;
	}

	Node* it = head;
	while(it->next != NULL){
		it = it->next;
	}
	it->next = newnode;
	return;
}

void printLL(){
	Node* it = head;
	while(it->next != NULL){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<it->data;
	return;
}

Node* reverseLL(){
	Node *current,*prev,*link;
	current = head;
	prev = NULL;

	while(current != NULL){
		link = current->next;
		current->next = prev;
		prev = current;
		current = link;
	}
	head = prev;
	return head;
}

Node* addOne(){
	Node* it = head;
	Node* last = NULL;
	
	while(it != NULL){
		if(it->data != 9){
			last=it;
		}
		it = it->next;
	}

	if(it->data != 9){
		it->data++;
		return head; 
	}

	if(last == NULL){
		Node* newnode = new Node();
		newnode->data = 1;
		newnode->next = head;
		head = newnode;
		Node* itr = head->next;
		while(itr != NULL){
			itr->data = 0;
			itr = itr->next; 
		}
		return head;
	}

	if(last != NULL){
		last->data++;
		Node* temp = last->next;
		while(temp != NULL){
			temp->data = 0;
			temp = temp->next;
		}
		return head;
	}
    return head;
}

int main(){
	head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(9);
	insert(9);
	printLL();
	cout<<endl;
	Node* it = reverseLL();
	while(it != NULL){
		cout<<it->data<<" ";
		it = it->next;
	}
	Node* itr = addOne();
	while(itr != NULL){
		cout<<itr->data<<" ";
		itr = itr->next;
	}
 	printLL();
	return 0;
}
