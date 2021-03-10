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

node* detect_loop(){
	node* slow = head;
	node* fast = head;

	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return slow;
	}
	return NULL;
}

node* find_loop_start_position(){
	node* meeting_point = detect_loop(); //point where slow and fast pointer meets;
	node* start = head;
	while(meeting_point != start){
		meeting_point = meeting_point -> next;
		start = start->next;
	}
	return start;
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
	node* ans = find_loop_start_position();
	cout<<' '<<ans->data;
	return 0;
}