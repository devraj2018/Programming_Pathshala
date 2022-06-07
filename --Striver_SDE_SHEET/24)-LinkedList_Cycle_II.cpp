#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	  if(head==NULL) return NULL;
        Node* slow=head,*fast=head;
        
        while( fast && fast->next)
        {   
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next; 
        }
        return slow;
}