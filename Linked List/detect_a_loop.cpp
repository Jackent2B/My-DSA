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

int detect_loop(){
	node* slow = head;
	node* fast = head;

	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;
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
	if(detect_loop()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}