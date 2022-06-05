 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode* slow=head,*fast=head,*prev=NULL;
        
        while( fast && fast->next)
        {   prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* temp=slow;
        
        prev->next=slow->next;
        delete slow;
        return head;
     }
};