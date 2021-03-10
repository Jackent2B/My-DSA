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

void addOne(){
	node* it = head;
	//to find the last element which is not equals to 9
	node* last = NULL;

	while(it->next != NULL){
		if(it->data != 9){
			last = it;
		}
		it = it->next;
	}


    // If last node is not equal to 9
    // add 1 to it and return
    if (it->data != 9) {
        it->data++;
        return;
    }

	// If list is of the type 9 -> 9 -> 9 ...
    if(last == NULL){
    	last = new node();
		last->data = 1;
		last->next = head;
		head = last; 
		node* s = head->next;
    	while(s != NULL){
    		s->data = 0;
    		s = s->next;
    	}
		return;
    }

    // For cases when the righmost node which
    // is not equal to 9 is not the last
    // node in the linked list
    last->data++;
    last = last->next;
 
    while (last != NULL) {
        last->data = 0;
        last = last->next;
    }
    return;
}

int main(){
    head = NULL;
	insert(9);
	insert(9);
	insert(9);
	insert(9);
	insert(9);
	insert(9);
	print();
	cout<<endl;
	addOne();
	print();
	return 0;
}