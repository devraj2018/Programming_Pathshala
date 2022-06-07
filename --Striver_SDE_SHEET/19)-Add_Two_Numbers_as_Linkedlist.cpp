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

Node *addTwoNumbers(Node *l1, Node *l2)
{
     if(!l2) return l1;
     if(!l1) return l2;
        
     Node* dummy=new Node(0);
     Node* tail=dummy;
     int carry=0;
       while(l1 ||l2 || carry) 
       {
             int sum= (l1?l1->data:0) + (l2?l2->data:0) +carry;
           
             tail->next=new Node(sum%10);
             carry=sum/10;
             tail=tail->next;
           
             l1= l1?l1->next:NULL;
             l2= l2?l2->next:NULL;
        }
        return dummy->next;
}