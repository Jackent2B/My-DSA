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
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		return;
	}

	node* it = head;
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
	cout<<it->data<<endl;
	return;
}

void getMiddleElement(){

	int n = 0;
	node* it = head; 
	while(it!= NULL){
		n++;
		it=it->next;
	}

	int mid = (n/2);

	node* temp = head;
	for (int i = 0; i < mid-1; ++i)
	{
		temp = temp->next;
	}
	cout<<temp->data<<endl;

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
	getMiddleElement();
	return 0;
}