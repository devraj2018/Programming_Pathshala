int countNodesinLoop(struct Node *head)
{
    if(head==NULL || head->next==NULL) return 0;
        
        Node* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
               break;
        }
        if(fast==NULL || fast->next==NULL) return 0;
        
        if(slow==slow->next) return 1;    //If there is self loop
        
        int count=1;
        slow=slow->next;
        while(slow!=fast)
        { slow=slow->next;
          count++;
        }

        
        return count;
        
}