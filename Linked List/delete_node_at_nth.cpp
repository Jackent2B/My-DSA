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
	
	node* temp1 = head;
	if (pos==1)
	{
		head = temp1->next; //head now points to second node.
		free(temp1);
		return;
	}

	//we have chosen n-2 because we have to move till n-1th node only.
	for (int i = 0; i < pos-2; i++)
		temp1 = temp1->next;

	//Now,temp1 pointing to (n-1)th node. 

	node* temp2;
	temp2 = temp1->next;   //temp2 pointing to (n)th node.
	temp1->next = temp2->next; // (n+1)th node.
	free(temp2);
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