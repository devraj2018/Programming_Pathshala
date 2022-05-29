class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        ListNode* even=new ListNode(0),*odd=new ListNode(0);
        ListNode* even_end=even,*odd_end=odd;
        bool isOdd=true;
        ListNode* nxt=NULL;
        while(temp!=NULL)
        {   nxt=temp->next;
            if(isOdd)
               {
                  odd_end->next=temp;
                  odd_end=odd_end->next;
                  temp->next=NULL;
                  isOdd=false;




                }
              else
               {
                 even_end->next=temp;
                 even_end=even_end->next;
                  temp->next=NULL;
                  isOdd=true;
              }
         temp=nxt;
         }
        odd_end->next=even->next;
        even_end->next=NULL;
        return odd->next;
   }
};