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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* preva=dummy,*prevB=dummy,*a=head,*b=head;
        for(int i=1;i<=right;i++)
        {
            if(i<left)
            {
                preva=a;
                a=a->next;
            }
             prevB=b;
             b=b->next;
            
        }
        preva->next=NULL;
        prevB->next=NULL;
        ListNode* revhead=reverse(a);
        
        preva->next=revhead;
        a->next=b;
        return dummy->next;
        
        
        
            
    }
};