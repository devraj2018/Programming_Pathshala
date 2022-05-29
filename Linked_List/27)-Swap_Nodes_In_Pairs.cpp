class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* remaining=head->next->next;
        ListNode*prev=head;
        ListNode* newhead=head->next;
        newhead->next=prev;
        prev->next=swapPairs(remaining);
        return newhead;
        
        


        
    }
};
// ------------Iterative Approach---------//

/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode *nxt,*curr=head,*temp;
        
        while(curr)
        {
            if(curr->next==NULL)
            {
               curr=curr->next;continue;
               
            }
            nxt=curr->next;
            temp=curr->next->next;
            prev->next=nxt;
            nxt->next=curr;
            curr->next=temp;
            prev=curr;
            curr=temp;
          
        }
        return dummy->next;
   }
};
*/