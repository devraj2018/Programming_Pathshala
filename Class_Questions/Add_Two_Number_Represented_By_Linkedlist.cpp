Node* add(Node*head1,Node* head2)
{
	Node * head1=reverse(head1);   // Implement reverse function 
	Node * head2=reverse(head2);
	int carry=0,sum=0;
	Node* newhead=new Node(0);
	Node* tail=newhead;
	while(head1 || head2 || carry)
	{  
		sum= (head1? head1->data:0)+(head2? head2->data:0) +carry;
		
		carry=sum/10;
		Node* newnode=new Node(sum%10);
		newnode->next=newhead->next;
        newhead->next=newnode;               //Every time insert at head,so we don't need to reverse
                                             //-it again at the time of returning
		
		head1= head1? head1->next:NULL;
		head2= head2? head2->next:NULL;
	
	}

    return newhead->next;

}