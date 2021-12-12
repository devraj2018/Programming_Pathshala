lass Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       if(head==NULL || head->next==NULL) return;
        
        Node* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
               break;
        }
        if(fast==NULL || fast->next==NULL) return;
        
        Node* prev=NULL;
        slow=head;
        while(slow->next!=fast->next)
        { 
          slow=slow->next;
          fast=fast->next;
        }
       fast->next=NULL;
        
    }
};