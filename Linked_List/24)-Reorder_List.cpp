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
     ListNode* reverse(ListNode*head)
    {
        ListNode* curr=head,*prev=NULL,*nxt=NULL;
        
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
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        
        ListNode *slow=head,*fast=head;
        ListNode* prevslow=NULL;
        while(fast && fast->next)
        {   prevslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* headA=head,*headB=NULL;
        if(fast==NULL) // Even case
        {
            prevslow->next=NULL;
            headB=slow;
        }
        else
        {
            headB=slow->next;
            slow->next=NULL;
        }
        
        headB=reverse(headB);
        
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        
        bool first=true;
        
        while(headA || headB)
        {
              if(first)
              {
                  tail->next=headA;
                  headA=headA->next;
                  tail=tail->next;
              }
            else
            {
                tail->next=headB;
                  headB=headB->next;
                  tail=tail->next;
            }
            
            first=!first;
        }
        head= dummy->next;
        
        
    }
};