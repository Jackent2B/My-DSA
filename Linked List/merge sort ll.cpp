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



// Find mid using The Tortoise and The Hare approach
node* findMid(node* head)
{
    node* slow = head;
    node* fast = head.next;
    while (fast != NULL && fast.next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two linked lists
node* merge(node head1, node head2)
{
    node* merged = new node(-1);
    node* temp = merged;
   
    // While head1 is not null and head2
    // is not null
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
   
    // While head1 is not null
    while (head1 != null) {
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
   
    // While head2 is not null
    while (head2 != null) {
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    return merged->next;
}

// Function to merge sort
node* mergeSort(node* head)
{
    if (head->next == NULL)
        return head;

    node* mid = findMid(head);
    node* head2 = mid->next;
    mid->next = null;
    node* newHead1 = mergeSort(head);
    node* newHead2 = mergeSort(head2);
    node* finalHead = merge(newHead1, newHead2);

    return finalHead;
}

void print(){
    node* it = head; 
    while(it->next != NULL){
        cout<<it->data<<" ";
        it=it->next;
    }
    cout<<it->data<<endl;
    return;
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
    node* finalHead = mergerSort();
    node* it = finalHead; 
    while(it->next != NULL){
        cout<<it->data<<" ";
        it=it->next;
    }
    cout<<it->data<<endl;
    return 0;
}