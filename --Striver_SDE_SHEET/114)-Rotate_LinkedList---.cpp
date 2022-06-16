#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/

int length(Node* head)
{ int c=0;
    while(head)
    {   
        head=head->next;
        c++;
    }
 return c;
}

Node *rotate(Node *head, int k) {
    
    if(head==NULL || head->next==NULL) return head;
        
        int len=length(head);
        
        if(k%len==0) return head;
        k=k%len;
        
        Node* curr=head,*prev=NULL;
        
        while(k--)
        {  
            curr=curr->next;
        }
        Node* tail=NULL;
        Node* currnow=head;
        while(curr)
        {
            prev=currnow;
            currnow=currnow->next;
            tail=curr;
            curr=curr->next;
        }
        
        
        tail->next=head;
        prev->next=NULL;
        head=currnow;
        return head;
    
    
    
    
}