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
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
          {
            slow=slow->next;
            fast=fast->next->next;
          }
       ListNode* head2=reverse(slow->next);
       slow->next=NULL;
       ListNode* head1=head;
       ListNode* temp;
       bool first=true;
       while(head1)
       {   if(first)
            {  temp=head1->next;
               head1->next=head2;
               head1=temp;
               first=false;
            }
           else
           {
               temp=head2->next;
               head2->next=head1;
               head2=temp;
               first=true; 
           }
            
       }
         
    }
};