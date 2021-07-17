Node* reverse(Node* head){
    
    Node* prev, *current, *next;
    current = head;
    prev  = NULL;
    
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
class Solution
{
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* first1 = reverse(first);
        Node* second1 = reverse(second);
        Node* head= new Node(NULL);
        Node* temp = head;
        
        int carry = 0;
        while(first1 != NULL || second1 !=NULL || carry!=0){
            int sum = 0;
            if(first1!= NULL){
                sum = sum + first1->data;
                first1 = first1->next;
            }
            
            if(second1 != NULL){
                sum = sum + second1->data;
                second1 = second1->next;
            }
            
            sum = sum + carry;
            carry = sum/10;
            Node* newnode = new Node(sum%10);
            temp->next = newnode;
            temp = temp->next;
        }
        return reverse(head->next);
    }
};