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
};