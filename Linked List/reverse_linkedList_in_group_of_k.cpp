#include <bits/stdc++.h>
using namespace std;
 
struct node{
	int data; //4 bytes
	Node* next; //4 bytes
};
 
/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{

    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}
 
void insert(Node** head_ref, int new_data)
{

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref); 
    (*head_ref) = new_node;
}
 
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
int main()
{
    Node* head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
 
    printList(head);
    head = reverse(head, 3);
    printList(head);
 
    return (0);
}
 