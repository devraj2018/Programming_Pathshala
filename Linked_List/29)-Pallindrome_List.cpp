class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
         ListNode* prev=NULL,*curr=head,*nxt=NULL;
         while(curr)
         { nxt=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nxt;

           
          }
        return prev;
        
        
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow)
        {  
             if(head->val!=slow->val) return false;
             slow=slow->next;
             head=head->next;
        }
        return true;
        
        
    }
};