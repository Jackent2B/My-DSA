#include <bits/stdc++.h>
using namespace std;

struct node{
	int data; //4 bytes
	node* next; //4 bytes
};

node* head;

void insert(int num){

	node* temp = new node();
	temp->data = num;
	temp -> next = head;
	head = temp;
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
	print();
	return 0;
}