int intersectPoint(Node* h1, Node* h2)  // Most Optimized ->only SIngle Traversal 
{  Node* head1=h1,*head2=h2;
    if(head1==NULL || head2==NULL) return -1;
    
    while(head1!=head2)
    {
        head1=head1->next;
        head2=head2->next;
        
        if(head1==head2) return head1->data;
        
        if(head1==NULL)  head1=h2;
        if(head2==NULL)  head2=h1;
        
    }
    return -1;
    
}

int getLength(Node* head) // Calculate Length of LL
{
    int l=0;
    while(head)
    {
        l++;head=head->next;
    }
    return l;
}
int intersectPoint(Node* head1, Node* head2) // I used 3 traversal in this
{   if(head1==NULL || head2==NULL) return -1;
    int l1=getLength(head1);
    int l2=getLength(head2);
    int x=abs(l1-l2);
    if(l1>l2)  while(x--) head1=head1->next;
    else while(x--) head2=head2->next;
     
     while(head1 && head2)
     {
         if(head1==head2) return head1->data;
         head1=head1->next;
         head2=head2->next;
         
     }
     return -1;
    
    
}

