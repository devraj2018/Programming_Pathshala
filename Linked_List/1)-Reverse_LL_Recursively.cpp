class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL) return NULL;    //To handle when Linkedlist is empty
        
        if(head->next==NULL) return head;    // When we are at last node;
        
        ListNode* nxt=head->next;  //Storing next so we can access it later
        
        head->next=NULL;   //Delinking
        
        ListNode* newhead=reverseList(nxt);  // Calling recursively for next node
        
        
        nxt->next=head;     // Linking part while returning
        
        return newhead;    // Every time return newhead
        
        
        
        
    }
};
