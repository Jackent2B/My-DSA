#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int length(Node* head){
    Node* it = head;
    int count = 0;
    while(it!=NULL){
        count++;
        it = it->next;
    }
    return count;
}

Node* getIntesectionNode(Node* A,Node* B){

    int m = length(A);
    int n = length(B);
    int d = n-m;

    //if length of A is graeter than B, then interchange A and B;
    if(m>n){
        Node* temp = A;
        A = B;
        B = temp;
        d = m-n;
    }

    for(int i=0; i<d; i++){
        B = B->next;
    }

    while(A !=NULL && B!=NULL){
       if(A==B)
            return A;
        A = A->next;
        B = B ->next;
    }
    return NULL;
}


int main(){
     Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    //ll1
    print(head1);
    cout<<endl;
    
    //ll2
    print(head2);
    cout<<endl;
    
    //intersection point
    cout<<getIntesectionNode(head1, head2)->data;
    return 0;
}