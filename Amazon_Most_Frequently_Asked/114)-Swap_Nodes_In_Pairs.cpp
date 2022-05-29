
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        
         
         while(head)
         {
              if(head->next==NULL) break; // last Single node
             
               ListNode* curr=head;
               ListNode* nxt=head->next;
               head=head->next->next;
             
               tail->next=nxt;
               nxt->next=curr;
               curr->next=head;
               tail=curr;
             
         }
        return dummy->next;
    }
};