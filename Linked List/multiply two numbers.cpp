Node* reverse(Node* head){
    
    Node* prev, *current, *next;
    prev  = NULL;
    current = head;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//reference: TUF
Node* multiplyTwoNumbers(struct Node* first, struct Node* second)
{
    Node* first1 = reverse(first);
    Node* second1 = reverse(second);  
    int num1 = 0, num2 = 0;       
    // Generate numbers from linked lists 
    while (first1 || second1) 
    { 
        if (first1) 
        { 
            num1 = num1*10 + first1->data; 
            first1 = first1->next; 
        } 
        if (second1) 
        { 
            num2 = num2*10 + second1->data; 
            second1 = second1->next; 
        } 
    } 
    // Return multiplication of  
    // two numbers 
    return num1*num2; 
}