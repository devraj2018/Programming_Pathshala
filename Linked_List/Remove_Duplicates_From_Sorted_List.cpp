class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr=head,*temp;
        while(curr)
        {   temp=curr->next;
            while(temp && curr->val==temp->val)
                { ListNode* hold=temp;
                  temp=temp->next;
                  delete hold;
                }
            curr->next=temp;
            curr=curr->next;
         }
        return head;
     }
};