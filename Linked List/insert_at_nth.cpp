#include <bits/stdc++.h>
using namespace std;

struct node{
	int data; //4 bytes
	node* next; //4 bytes
};

node* head;

void insert_at_nth(int num, int pos){
	
	node* temp = new node();
	temp->data = num;
	temp->next = NULL;

	if(pos == 1){
		temp->next = head;
		head = temp;
		return;
	}

	node* it = head;
	//we have chosen n-2 because we have to move till n-1th node only.
	for (int i = 0; i < pos-2; ++i)
		it = it->next;

	temp->next = it->next;
	it->next = temp;

	return;
}

void insert(int num){

	node* temp = new node();
	temp->data = num;
	temp -> next = NULL;
	
	node* it = head;

	if(head == NULL){
		head = temp;
		return;
	}
		
	while(it->next != NULL){
		it = it->next;
	}

	it->next = temp;
	return;
}

void print(){
	node* it = head; 
	while(it->next != NULL){
		cout<<it->data<<" ";
		it=it->next;
	}
	cout<<it->data;
	return;
}

int main(){
    head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert_at_nth(7,3);
	print();
	return 0;
}