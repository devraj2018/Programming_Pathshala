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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
         ListNode* curr=head->next;
         ListNode* prev=head;
         prev->next=NULL;
        
         while(curr)
            {
                if(curr->val==prev->val)
                   {
                     ListNode* temp=curr;
                     curr=curr->next;
                     delete temp;
                   }
                else
                    {
                    prev->next=curr;
                    prev=curr;
                    curr=curr->next;
                    prev->next=NULL;
                  }
             }
        return head;
    }
};