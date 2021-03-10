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

void removeNode(int key){

	//if linked list is empty
	if(head == NULL)
		return;

	// If the list contains only a single node
	if(head->data ==key && head->next == head){
		free(head);
		head = NULL;
	}

	Node* it = head;
	//if head is to be deleted
	if(head->data == key){
		while(it->next != head){
			it = it->next;
		}
		it->next = head->next;
		free(head);
		head = it->next;
	}

	// Either the node to be deleted is not found 
    // or the end of list is not reached
    while(it->next!=head && it->next->data != key) 
    {
        it=it->next;
    }
     
    // If node to be deleted was found
    if(it->next->data==key) 
    {
        d=it->next;
        it->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
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
	removeNode(5);
	cout<<"After removing node 5"<<endl;
	print();	
	removeNode(1);
	cout<<"After removing node 1"<<endl;
	print();
	removeNode(6);
	cout<<"After removing node 6"<<endl;
	print();
	return 0;
}