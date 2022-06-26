class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* head=NULL;  
          if(!l1) return l2;
          if(!l2) return l1;

         ListNode* dummy= new ListNode(0);
         ListNode* tail=dummy;

        
          while(l1 && l2)
          {    if(l1->val<=l2->val)
                   {
                    tail->next=l1; 
                   l1=l1->next;
                   }
               else
                   {
                     tail->next=l2; l2=l2->next;
                   }
             tail=tail->next;
            
    }
        
        if(l1) tail->next=l1;
        if(l2) tail->next=l2;

        return dummy->next;
       
    }
};