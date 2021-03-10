/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    // An empty linked list is circular 
    if (head == NULL) 
       return true; 
  
    // Next of head 
    Node *it = head; 
  
    // This loop would stop in both cases (1) If 
    // Circular (2) Not circular 
    while (it->next != NULL && it->next != head) 
       it = it->next; 
  
    // If loop stopped because of circular 
    // condition 
    return (it->next == head); 
}