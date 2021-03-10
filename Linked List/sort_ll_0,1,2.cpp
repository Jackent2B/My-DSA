#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* link; 
};

//declaring haed as global
node* head;

void insert(int x){
	node* temp = new node();
	temp->data = x;
	//newly created temp->link will point to the 
	//value present in the HEAD.
	temp->link = head;
	head = temp;
};

void sortLinkedList() {
    
    //creating an array to keep the count of each element.
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0  
    node *ptr = head;  

    while (ptr != NULL)  
    {  
        count[ptr->data] += 1;  
        ptr = ptr->link;  
    }  
  
    int i = 0;  
    ptr = head;  
  
    while (ptr != NULL)  
    {  
        if (count[i] == 0)  
            ++i;  
        else
        {  
            ptr->data = i;  
            --count[i];  
            ptr = ptr->link;  
        }  
    } 
    //ptr = head;
    //return ptr;
}

void print(){
	node* temp = head;
	while(temp!= NULL){
		printf("%d",temp->data);
		temp = temp->link; 
	}
}

int main(){
	head = NULL;
	int n,x;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	print();
	cout<<"\n";
	sortLinkedList();
	print();

}