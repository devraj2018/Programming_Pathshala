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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int n)
{
        LinkedListNode<int>* dummy=new LinkedListNode<int>(0);
        dummy->next=head;
        
        LinkedListNode<int>* slow=head,*fast=head,*prev=dummy;
        if(n==0) return head;
        while(n && fast)
        {
            n--;fast=fast->next;
        }
        
        while(fast)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        return dummy->next;
}