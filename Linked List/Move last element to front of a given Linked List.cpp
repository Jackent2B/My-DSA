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

void move_last_element_to_first(){
	
	if(head == NULL || head->next == NULL)
		return;

	node* temp = head;
	node* second_last = NULL;
	while(temp->next != NULL){
		second_last = temp;
		temp = temp->next;
	}

	second_last->next = NULL;
	temp->next = head;
	head = temp;

}

int main(){
    head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	cout<<"Elements of array : "<<endl;
	print();
	cout<<endl;
	cout<<"After Moving last element to first : "<<endl;
	move_last_element_to_first();
	print();
	return 0;
}