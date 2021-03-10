//reverse function
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

/* Deletes nodes which have
greater value node(s) on left side */
Node* removeNodes(Node* head)
{
    Node* current = head;
 
    /* Initialize max */
    Node* maxnode = head;
    Node* temp;
 
    while (current != NULL && 
           current->next != NULL) 
    {
        /* If current is smaller than max,
        then delete current */
        if (current->next->data < maxnode->data) 
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
 
        /* If current is greater than max, 
            then update max and move current */
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
    return head;
}
 

/* Deletes nodes which have a node with 
greater value node on left side */
Node* remove_node_right_side(Node* head)
{

    Node* rev_head = reverse(head);
 
    /* 2) In the reversed list, delete nodes 
    which have a node with greater value node 
    on left side. Note that head node is never 
    deleted because it is the leftmost node.*/
    Node* new_head = removeNodes(rev_head);
 
    /* 3) Reverse the linked list again to 
    retain the original order */
    Node* original_head = reverse(new_head);
    return original_head;
}


class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node*ans = remove_node_right_side(head);
        return ans;
    }
    
};