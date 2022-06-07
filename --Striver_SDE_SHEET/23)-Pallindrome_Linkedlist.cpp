#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
 LinkedListNode<int>* reverse( LinkedListNode<int>* head) {
        LinkedListNode<int>* prev=NULL,*curr=head,*nxt=NULL;
        
        while(curr)
        { nxt=curr->next;

        
          curr->next=prev;
          prev=curr;
          curr=nxt;
     }
        return prev;
        
        
    }
     
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL) return true;
        
        LinkedListNode<int>* slow=head,*fast=head,*prev=NULL;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        LinkedListNode<int>* newhead;
        if(fast==NULL)
        {   prev->next=NULL;
            newhead=slow;
        }
        else
        {  
            newhead=slow->next;
             slow->next=NULL;
            
        }
        newhead=reverse(newhead);
        
        while(newhead)
        {
            if(newhead->data!=head->data) return false;
            newhead=newhead->next;
            head=head->next;
        }
        return true;
        

}