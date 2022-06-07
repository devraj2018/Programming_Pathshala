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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
      if(head==NULL) return NULL;
        
         if(head->next==NULL) return head;
        
         
         LinkedListNode<int>* nxt=head->next;
         head->next=NULL;
        
        LinkedListNode<int>* newhead=reverseLinkedList(nxt);
         nxt->next=head;
        return newhead;
}