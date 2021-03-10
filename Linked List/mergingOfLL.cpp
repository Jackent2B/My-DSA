#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next; 
};

void insert(node* head,int x){
	node* temp = new node();
	temp->data = x;
	//newly created temp->next will point to the 
	//value present in the HEAD.
	temp->next = head;
	head = temp;
};

void print(node* head){
	node* temp = head;
	while(temp!= NULL){
		printf("%d",temp->data);
		temp = temp->next; 
	}
}

node* mergingList(node*head1,node* head2){

	node* p = head1;
	node* q = head2;
	node* sorted = NULL;

	node *head;
	
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	
	if(p && q)
	{
		if(p->data <= q->data)
		{
			sorted = p;
			p = p->next;
		}
		else
		{
			sorted = q;
			q = q->next;
		}
		
	}
	
	head = sorted;
	
	while(p && q)
	{
		if(p->data <= q->data)
		{
			sorted->next = p;
			sorted = sorted->next;
			p = p->next;
		}
		else
		{
			sorted->next = q;
			sorted = sorted->next;
			q = q->next;
		}
	}
	
	if(p==NULL)
		sorted->next = q;
	
	if(q==NULL)
		sorted->next = p;

	return head;
}

int main(){
    //declaring haed as global
    node* head1 = NULL;
    node* head2 = NULL;
	int n1,n2,x;
	scanf("%d",&n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d",&x);
		insert(head1,x);
	}
	print(head1);
	cout<<endl;

    scanf("%d",&n2);
	for (int j = 0; j < n2; j++)
	{
		scanf("%d",&x);
		insert(head2,x);
	}
	print(head2);
	cout<<endl;

	node* head3=mergingList(head1,head2);
    print(head3);

}