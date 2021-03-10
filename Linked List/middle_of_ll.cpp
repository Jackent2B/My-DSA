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


//time compleit: O(N/2) tortoise method
void getMiddleElement(){

	node* slow = head;
	node* fast = head;
//Note:
//Error:  while(fast->next!= NULL && fast!= NULL)
//Correct: while(fast!= NULL && fast->next != NULL)
	while(fast!= NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<slow->data<<endl;
}	

int main(){
    head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	print();
	getMiddleElement();
	return 0;
}