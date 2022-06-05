class Solution {
public:
     ListNode* reverse(ListNode* head) {
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
        
        ListNode* slow=head,*fast=head,*prev=NULL;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* newhead;
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
            if(newhead->val!=head->val) return false;
            newhead=newhead->next;
            head=head->next;
        }
        return true;
        
    }
};