ListNode* Solution::swapPairs(ListNode* A) {

   ListNode* dummy=new ListNode(0);
   ListNode* tail=dummy;
   dummy->next=A;

   ListNode* curr=A;
  while(curr&& curr->next)
  {
       ListNode* a=curr;
       ListNode* b=curr->next;
       curr=curr->next->next;

       tail->next=b;
       b->next=a;
       a->next=curr;
       tail=a;
  }
  return dummy->next;


}
