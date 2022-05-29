/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode* slow=head,*fast=head;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) break;
        }
        if(fast==NULL || fast->next==NULL) return NULL;
        
        slow=head;
        while(slow!=fast)
        {
              slow=slow->next;
              fast=fast->next;
        }
        return slow;
        
    }
};