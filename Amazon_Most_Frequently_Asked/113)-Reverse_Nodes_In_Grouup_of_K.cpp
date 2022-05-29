/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        ListNode* reverse (ListNode* head) {
          ListNode* prev=NULL,*curr=head,*nxt=NULL;
          while(curr)
             {   nxt=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=nxt;
             }
         return prev;
       }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
         if(head==NULL || head->next==NULL || k==1) return head; 
        
         int l=0;
         ListNode* temp=head;
         while(temp)
            {
                l++;temp=temp->next;
            }
        
        
        int iteration=l/k;
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        
        ListNode* curr=head;
        
        for(int i=0;i<iteration;i++)
        {
              int x=k;
              ListNode* prevhead=curr;
              ListNode* prev=NULL;
              while(x-- && curr)
              {   prev=curr;
                  curr=curr->next;
              }
              prev->next=NULL;
              ListNode* revhead=reverse(prevhead);
              
              prevhead->next=curr;
              tail->next=revhead;
              tail=prevhead;
        
            
        }
        return dummy->next;
        
        
    }
};