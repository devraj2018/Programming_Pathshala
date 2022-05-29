
ListNode* Solution::deleteDuplicates(ListNode* head) {

    ListNode* dummy= new ListNode(0);
    ListNode* tail=dummy;
    dummy->next=head;

    while(head)
    {     int val=head->val;
          if((head->next==NULL) || (head->next && head->val!=head->next->val))
            { tail->next=head;
              tail=tail->next;
              head=head->next;
            }
          else{

            
          
               while(head && head->val==val)
                 {
                   ListNode* todelete= head;
                   head=head->next;
                   delete todelete;
                 }
               tail->next=head;
               }
     }
    return dummy->next;


}
