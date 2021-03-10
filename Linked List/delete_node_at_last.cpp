#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* head;

void insert(int num){
	node* temp = new node();
	temp->data = num;
	temp->next = NULL;

	if(head == NULL){
		head=temp;
		return;
	}

	node* it = head;
	while(it->next != NULL){
		it= it->next;
	}
	it->next = temp;
	return;
}

void print(){
	node* it = head;
	while(it->next!= NULL){
		cout<<it->data<<" ";
		it = it->next;
	}
	cout<<it->data<<endl;
}

void delete_node(int pos){
	
	node* temp = head;
	while(temp->next != NULL){
		temp=temp->next;
	}
	free(temp);
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
	int pos = 3;
	delete_node(pos);
	print();
	return 0;
}