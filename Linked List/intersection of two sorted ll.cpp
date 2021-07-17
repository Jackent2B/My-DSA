Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* head = NULL;
    Node* cur = NULL;
    while(temp1 != NULL && temp2!= NULL){
        if(temp1->data == temp2->data){
            if(head == NULL){
                Node* x = new Node(temp1->data);
                head = x;
                cur = x;
            }
            else{
                Node* x = new Node(temp1->data);
                cur->next = x;
                cur = cur->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else if(temp1->data > temp2->data){
            temp2 = temp2->next;
        }
    }
    return head;   
}