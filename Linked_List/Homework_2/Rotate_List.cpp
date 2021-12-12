class Solution {
public:
     int getLength(ListNode* head) // Calculate Length of LL
        {
           int l=0;
           while(head)
            {
              l++;
              head=head->next;
            }
           return l;
        }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int l=getLength(head);
        k=k%l;
        if(k==0) return head;
        ListNode* prev=NULL;
        ListNode* temp=head,*start=head,*last;
        while(k--) temp=temp->next; 
    
        while(temp)
        {   prev=start;
            start=start->next;
            last=temp;
            temp=temp->next;
        }
        last->next=head;
        prev->next=NULL;
        head=start;
        return head;
        
        
    }
};