class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
        
        while(curr)
        { nxt=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nxt;
         }
        return prev;
        
        
    }
    ListNode* reverseBetween(ListNode* head, int a, int b) {
        
        if(head==NULL) return NULL;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev_a=dummy,*first,*second,*curr=head;
        int i=1;
        while(i<a)
         {   prev_a=curr;
             curr=curr->next;
             i++;
         }
        first=curr;
        while(i<b)
        { curr=curr->next;i++;
        }
        second=curr;
        curr=curr->next;
        second->next=NULL;    // Link Breaking is also Important
        prev_a->next=reverseList(first);
        first->next=curr;
        return dummy->next;
        
        
        
    }
};