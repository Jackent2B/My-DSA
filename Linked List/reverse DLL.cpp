#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;  
};

//declaring head as global
node* head;

struct node* GetNewNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	//newly created temp->next will point to the 
	//value present in the HEAD.
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
};

void insertAtHead(int x){
	node* newNode = GetNewNode(x);
	if (head==NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;

}

void print(){
	node* temp = head;
	printf("Forward: ");
	while(temp!= NULL){
		printf("%d",temp->data);
		temp = temp->next; 
	}
	printf("\n");
}

void printReverse(){
	node* temp = head;
	if (temp == NULL) return; //empty list

	//going to the last node
	while(temp->next != NULL){
		temp=temp->next;
	}

	printf("Reverse: ");
	while(temp!= NULL){
		printf("%d",temp->data);
		temp = temp->prev; 
	}
	printf("\n");
}

void reverseDLL()
{
    //Your code here

	node* current = head;
	node* temp = NULL;

	while(current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

    /* Before changing the head, check for the cases like empty 
        list and list with only one node */

	if(temp != NULL){
		temp = temp->prev;
		head = temp;
	}
    return;
}

int main(){
	head = NULL;
	insertAtHead(1);
	insertAtHead(2);
	insertAtHead(3);
	insertAtHead(4);
	insertAtHead(5);
	insertAtHead(6);
	print();
	cout<<endl;
	reverse_dll();
	cout<<"After reversal"<<endl;
	print();
}