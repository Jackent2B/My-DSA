void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{

    Node *slow = head;  
    Node *fast = head;  
      
    if(head == NULL)  
        return;  
      
    /* If there are odd nodes in the circular list then  
       fast_ptr->next becomes head and for even nodes  
       fast_ptr->next->next becomes head */
    
    //Tortoise method
    while(fast->next != head &&  
          fast->next->next != head)  
    {  
        fast = fast->next->next;  
        slow = slow->next;  
    }  
      
    /* If there are even elements in list 
       then move fast_ptr */
    if(fast->next->next == head)  
        fast = fast->next;  
          
    /* Set the head pointer of first half */
    *head1_ref = head;  
          
    /* Set the head pointer of second half */
    if(head->next != head)  
        *head2_ref = slow->next; 
                  
    /* Make first half circular */
    slow->next = head;
          
    /* Make second half circular */
    fast->next = *head2_ref;  
  
    
}