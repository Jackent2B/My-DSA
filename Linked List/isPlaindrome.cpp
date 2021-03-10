//reverse a linked list
Node* reverse(Node* ptr){
    Node* prev,*current,*next;
    prev = NULL;
    current = ptr;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ptr = prev;
    return ptr;
}

bool isPalindrome(Node *head)
{
    //Your code here
    Node* slow = head;
    Node* fast = head;

    //find middle element using tortoise method
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* reverse_start = slow->next;
    
    //reversing the linked list after middle element
    Node* reverse_ptr_head = reverse(reverse_start);
    
    //traversing the linked list from start and from after the middle element
    Node* start1 = head;
    Node* start2 = reverse_ptr_head;
    while(start2 != NULL){
        if(start1->data != start2->data){
            return 0;
        }
        start1 = start1->next;
        start2 = start2->next;
    }
    return 1;
}