class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1,*curr2=l2;
        ListNode*dummy=new ListNode(0);
        ListNode* prev=dummy;
        int carry=0;
        int sum=0;
        while(curr1 || curr2 || carry)
        {
            sum= (curr1?curr1->val:0)+(curr2?curr2->val:0) +carry;
            
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            prev->next=newNode;
            prev=newNode;
            curr1=curr1?curr1->next:curr1;
            curr2=curr2?curr2->next:curr2;
        }
        return dummy->next;
    }
};