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

int findIntersection(Node *headA, Node *headB)
{
      Node* currA=headA,*currB=headB;
        
        while(currA && currB)
        {
            if(currA==currB) return currA->data;
            
            currA=currA->next;
            currB=currB->next;
            
            if(currA==NULL) currA=headB;
            else if(currB==NULL) currB=headA;
            
        }
        return -1;
}