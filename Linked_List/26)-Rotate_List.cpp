
class Solution {
public:
    int length(ListNode* l1)
    {
        int l=0;
        while(l1)
        {
            l++;
            l1=l1->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL) return head;
        
        int len=length(head);
        
        if(k%len==0) return head;
        k=k%len;
        
        ListNode* curr=head,*prev=NULL;
        
        while(k--)
        {  
            curr=curr->next;
        }
        ListNode* tail=NULL;
        ListNode* currnow=head;
        while(curr)
        {
            prev=currnow;
            currnow=currnow->next;
            tail=curr;
            curr=curr->next;
        }
        
        
        tail->next=head;
        prev->next=NULL;
        head=currnow;
        return head;
        
    }
};