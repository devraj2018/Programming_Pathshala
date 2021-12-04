int function(Node* head)
{
	if(head == NULL)
		return INT_MIN;
	int var;
	Node* prev =NULL;
	Node* temp = head;
	while(temp->next != head)
	{   prev=temp;
		temp = temp->next;
		
	}
	if(temp == head)
	{
		var = head->data;
		head = NULL;
		return var;
	}
    prev->next=temp->next;
	var = temp->data;
	return var;
}