
// O(1)Space O(n)Time
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        bool is_l1=true;
        int carry=0;
        int sum;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        
       
        while(l1 || l2 || carry)
        {
             sum= (l1?l1->val:0)+(l2?l2->val:0) + carry;
             
            
             if(l1)
                {  l1->val= sum%10;
                   prev->next=l1;
                }
             else if(l2)
               {
                 l2->val=sum%10;
                 prev->next=l2;
              }
             else  prev->next=new ListNode(sum%10);
                
             carry=sum/10;
             prev=prev->next;
             
             l1= l1?l1->next:NULL;
             l2= l2?l2->next:NULL;
            
        }
      
        return dummy->next;
    }
};

//   O(N) Space and O(n) Time
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        int carry=0;
        int sum;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        
       
        while(l1 || l2 || carry)
        {
             sum= (l1?l1->val:0)+(l2?l2->val:0) + carry;
             
            
             ListNode* temp=new ListNode(sum%10);
             carry=sum/10;
             prev->next=temp;
             prev=temp;
            
             ListNode* temp1=l1,*temp2=l2;
             l1= l1?l1->next:NULL;
             l2= l2?l2->next:NULL;
             delete temp1;delete temp2;
          }
      
        return dummy->next;
        
    }
};