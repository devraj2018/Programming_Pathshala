class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
         ListNode* prev=NULL,*curr=head,*nxt=NULL;
        
         while(curr)
           {
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
             
           }
        return prev;
   }
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return ;
        
        ListNode* slow=head,*fast=head,*prev=NULL;
        
        while(fast && fast->next)
        {    prev=slow;
             slow=slow->next;
             fast=fast->next->next;
        }
        
        if(fast==NULL)  prev->next=NULL;
        else
          {
            prev=slow;
            slow=slow->next;
            prev->next=NULL;
          }
        
        slow= reverse(slow);
        ListNode* head1=head,*head2=slow;
        ListNode* dummy=new ListNode(),*tail=dummy;
        
        bool first=true;
    
        while(head1 || head2)
           {
             if(first)
                {
                 tail->next=head1;
                 head1=head1->next;
                 tail=tail->next;
                 first=false;
                }
             else
               {
                 tail->next=head2;
                 head2=head2->next;
                 tail=tail->next;
                 first=true;
              }
          }
       head= dummy->next;
        
     }
};