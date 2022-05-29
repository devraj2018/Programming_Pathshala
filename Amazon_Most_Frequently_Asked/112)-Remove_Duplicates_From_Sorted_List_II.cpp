
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* tail=dummy;
        ListNode* curr=head;
        
         while(curr)
             {
            
                 if(curr->next && curr->val!=curr->next->val)
                     {
                          tail=curr;
                          curr=curr->next;
                     }
                 else if(curr->next==NULL)
                    {
                     curr=curr->next;
                    }
                 else
                    {
                      int data=curr->val; 
                      while(curr && curr->val==data)
                        {
                          ListNode* temp=curr;
                          curr=curr->next;
                          delete temp;
                        }
                      tail->next=curr;
                     }
               }
        return dummy->next;
        
        
        
    }
};