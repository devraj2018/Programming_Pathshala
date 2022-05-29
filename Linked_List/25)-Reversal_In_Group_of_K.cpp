 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
         while(curr)
        { nxt=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nxt;
        }
        return prev;
    }
    int getLength(ListNode* head)  {
           int l=0;
           while(head)
            {
              l++;
              head=head->next;
            }
           return l;
        }



    ListNode* reverseKGroup(ListNode* head, int k) {           // Iterative Approach
        if(head==NULL || head->next==NULL || k==1 ) return head;
        
        int n=getLength(head); 
        ListNode* curr=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* temp,*prevhead;
        
        
        for(int i=1;i<=n/k;i++)
        {    prevhead=curr;
             for(int j=1;j<=k;j++) {
                 temp=curr;
                 curr=curr->next;
             }
            temp->next=NULL;   // Delinking part is very Inportant
            prev->next=reverseList(prevhead);  
            prevhead->next=curr;
            prev=prevhead;
           
        }
  
        return dummy->next;
    }

     ListNode* reverseKGroup(ListNode* head, int k)   // Recursive Approach
    {
        if(head==NULL || head->next==NULL || k==1 ) return head;
        
        int size=0;
        ListNode* curr=head;
        ListNode* prev;
        while(curr && size<k)
        { prev=curr;
            curr=curr->next;
            size++;
         
        }
        if(size<k)
            return head;
        prev->next=NULL;  // Delinking part is very Inportant --> Don't forget this Got error by omiiting this 
        ListNode* newhead=reverseList(head);
        head->next=reverseKGroup(curr, k);
        return newhead;
        
    }
    
};