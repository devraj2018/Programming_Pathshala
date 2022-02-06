class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* first=head,*last=head;
        while(last && last->next)
        {
            first=first->next;
            last=last->next->next;
         }
        return first;
        
        
    }
};