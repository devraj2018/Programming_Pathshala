int fractional_node(struct Node *head, int k)
{
    int l=0;
    Node* temp=head;
    while(temp)
    {
        l++;temp=temp->next;
    }
    int x= (l%k==0)?l/k:l/k+1;
    int ans;
    for(int i=1;i<=x;i++)
    {

        
         ans=head->data;
         head=head->next;
        
        
    }
   
    return ans;
}
