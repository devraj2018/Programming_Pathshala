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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* currA=headA,*currB=headB;
        
        while(currA && currB)
        {
            if(currA==currB) return currA;
            
            currA=currA->next;
            currB=currB->next;
            
            if(currA==NULL) currA=headB;
            else if(currB==NULL) currB=headA;
            
        }
        return NULL;
    }
};