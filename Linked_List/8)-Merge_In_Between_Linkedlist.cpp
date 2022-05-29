
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
         ListNode* dummy=new ListNode(0);
        dummy->next=list1;
        ListNode* prev=dummy;
        ListNode* curr=list1;
        
        for(int i=1;i<=b+1;i++)
           {
              if(i<=a)
                {
                   prev=curr;
                   curr=curr->next;
               }
               else
                 {
                    ListNode* temp=curr;
                    curr=curr->next;
                    delete temp;
                 }
            }
        
        prev->next=list2;
        while(prev->next)   prev=prev->next;
        
        
        prev->next=curr;
        return dummy->next;
        
        
    }
};