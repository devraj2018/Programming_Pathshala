class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* prev=NULL;
        ListNode* temp=head,*start=head;
        while(n--) temp=temp->next; 
    
        while(temp)
        {   prev=start;
            start=start->next;
            temp=temp->next;

            
        }
        if(prev==NULL) return head->next;
        prev->next=start->next;
        return head;
    }
};