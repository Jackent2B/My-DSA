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


int main(){
	head = NULL;
	insertAtHead(2);print();printReverse();
	insertAtHead(4);print();printReverse();
	insertAtHead(6);print();printReverse();
}