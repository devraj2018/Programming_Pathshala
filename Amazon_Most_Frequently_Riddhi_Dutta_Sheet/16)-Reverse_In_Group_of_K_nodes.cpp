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
    ListNode* reverse(ListNode* head)
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
    int length(ListNode* head)
    {
        ListNode* curr=head;
        int l=0;
        while(curr)
        {
            l++;
            curr=curr->next;
        }
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL || k==1) return head;
        
        int len=length(head);
        int rotation= len/k;
        
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        
        for(int i=1;i<=rotation;i++)
        {
            ListNode* currHead=head;
            ListNode* prev=NULL;
            int kk=k;
            
            while(kk--)
            {   prev=head;
                head=head->next;
            }
            prev->next=NULL;
            
            tail->next=reverse(currHead);
            currHead->next=head;
            tail=currHead;
            
        }
        return dummy->next;
        
       
    }
};