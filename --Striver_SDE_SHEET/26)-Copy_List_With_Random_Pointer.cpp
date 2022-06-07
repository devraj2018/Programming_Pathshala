#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
     LinkedListNode<int>* currA=head;
        
         LinkedListNode<int>* dummy=new LinkedListNode<int>(0);
         LinkedListNode<int>* tail=dummy;
        
        unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
        while(currA)
        {
            tail->next=new LinkedListNode<int>(currA->data);
            mp[currA]=tail->next;
            currA=currA->next;
            tail=tail->next;
        }
        LinkedListNode<int>* currB=dummy->next;
        currA=head;
        while(currA)
        {
             currB->random= mp[currA->random];
             currA=currA->next;
             currB=currB->next;
            
        }
        return dummy->next;
}
