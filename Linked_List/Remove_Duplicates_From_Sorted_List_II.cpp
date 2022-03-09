class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy,*curr=head,*temp;
        int val;
        bool isDup;
        while(curr)
        {   temp=curr->next;
            isDup=false;
            while(temp && curr->val==temp->val)
                { ListNode* hold=temp;
                  temp=temp->next;
                   delete hold;
                  isDup=true;
                }
            if(isDup)
              {   prev->next=temp;
                  curr=temp;
              }
           else{
             
               prev=curr;
              curr=curr->next;
              }
         }
        return dummy->next;
        
    }
};