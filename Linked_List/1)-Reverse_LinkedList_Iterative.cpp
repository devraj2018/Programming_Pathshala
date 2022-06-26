
// struct node{
//     int data;
//     node* next;
//     Node(int _d)
//     {
//         data=_d;
//         next=NULL;
//     }
// };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
        
        while(curr)
        { 
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
   }
};