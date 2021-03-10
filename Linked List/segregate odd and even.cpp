//segregate odd and even
Node* divide(int N, Node *head){
        // code here
        Node* it = head;
        
        //heads of even and odd
        Node* even_head = NULL;
        Node* odd_head = NULL;
        
        //iterators of even and odd
        Node* even = NULL;
        Node* odd = NULL;
        
        while(it != NULL){
            if(it->data%2 == 0 ){
                
                if(even_head == NULL){
                    even_head = it;
                    even = it;   
                }
                else{
                    even->next = it;
                    even = even ->next;
                }
            }
            else{
                if(odd_head == NULL){
                    odd_head = it;
                    odd = it;   
                }
                else{
                    odd->next = it;
                    odd = odd->next;
                }
            }
            it = it->next;
        }
        
        if(even_head == NULL || odd_head == NULL)
            return head;
        
        even->next = odd_head;
        odd->next = NULL;
        head = even_head;
        return head;
    }