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

//reference: code Libraray video
void removeLoop(){
    // code here
    node* slow = head;    
    node* fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}

	if(slow == head){
		while(fast->next != slow){
			fast = fast->next;
		}
		fast->next = NULL;
	}
	else if(slow == fast){
		slow = head;
		while(fast->next != slow->next){
			fast = fast -> next;
			slow = slow->next;
		}
		fast->next = NULL;	
	}}

int main(){
    head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	print();
	removeLoop();
	return 0;
}