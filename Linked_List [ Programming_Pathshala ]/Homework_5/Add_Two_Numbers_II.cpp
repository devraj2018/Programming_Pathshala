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
     ListNode* reverseList(ListNode* head) {
         ListNode* prev=NULL,*curr=head,*nxt=NULL;
          while(curr)
           { nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
           }
          return prev;
         }
         
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=reverseList(l1);
        ListNode* curr2=reverseList(l2);
        ListNode*dummy=new ListNode(0);
        ListNode* prev=dummy;
        int carry=0;
        int sum=0;
        while(curr1 || curr2 || carry)
        {
            sum= (curr1?curr1->val:0)+(curr2?curr2->val:0) +carry;
            
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            
            ListNode* temp=prev->next;        // No need to reverse back in end
            newNode->next=temp;              // Bcz here I am adding every new Node at head
            prev->next=newNode;             // So it will automatically be reversed acc to my question
            curr1=curr1?curr1->next:curr1;
            curr2=curr2?curr2->next:curr2;
       }
      
         
      return dummy->next;
        
    }
};