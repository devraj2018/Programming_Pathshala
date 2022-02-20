 
class Solution {
public:
    
    ListNode* merge(ListNode* a,ListNode* b)
       {
         if(a==NULL) return b;
         if(b==NULL) return a;
        
          ListNode* head=NULL,*tail=NULL;
          if(a->val<=b->val)
           {
             head=a; tail=a; a=a->next;
           }
          else
          {
            head=b; tail=b;  b=b->next; 
          }
        
        while(a && b)
         {   if(a->val<=b->val)
                  { tail->next=a;
                    tail=a;
                    a=a->next;
                  }
              else
                  {  tail->next=b;
                     tail=b;
                     b=b->next;
                 }
         }
        
        if(a) tail->next=a;
        if(b) tail->next=b;
        
        return head;
    }
    ListNode* middle(ListNode* head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(  fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
         }
        return slow;
    }
     
    ListNode* sortList(ListNode* head) {
        
         if(head==NULL) return NULL;
        
         if(head->next==NULL) return head;
        
         ListNode* mid= middle(head);
         
         ListNode* secondhead=mid->next;
         mid->next=NULL;
        
         ListNode* a=sortList(head);
         ListNode* b=sortList(secondhead);
         return merge(a,b);
     }
};