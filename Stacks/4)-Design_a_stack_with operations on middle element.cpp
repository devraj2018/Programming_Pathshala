How to implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 

Implement with doubly LL,Insertion and deletion at same end,
for mid store pointer

/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;



class MyStack{
	
	struct Node{
		int data;
		Node* next,*prev;
		Node(int _data)
		{   data= _data;
	     	next=NULL;
	     	prev=NULL;
	 	}
	};
   public:
       Node* head,*middle;
       int curr_size;
      
       MyStack(){
       	curr_size=0;
       	head=NULL;
       	middle=NULL;
       }
       
       void push(int x)
       {   curr_size++;
       
       	   if(curr_size==1)
       	    { 
       	    	head=new Node(x);
       	     	middle=head;
       	    	return;
       	    }
       	    
       	    Node* newnode= new Node(x);
       	    newnode->next=head;
       	    head->prev=newnode;
       	    head=newnode;
       	    
       	    if(curr_size%2==1)
       	    {
       	    	middle=middle->prev;
       	    }
       	    
       }
       void pop(){
       	  if(head==NULL) return;
       	  
       	  curr_size--;
       	  
       	  if(head==middle)
       	  {
       	  	 Node* temp=head;
       	  	 head=NULL;
       	  	 middle=NULL;
       	  	 delete temp;
       	  	 return;
       	  	
       	  }
       	  
       	  Node* temp=head;
       	  head=head->next;
       	  head->prev=NULL;
       	  delete temp;
       	  
       	  if(curr_size%2==0)
       	  {
       	  	middle=middle->next;
       	  }
       	 
       }
       
       int findMiddle()
       {
       	  if(middle==NULL) return -1;
       	  return middle->data;
       }
       
       void deleteMiddle()
       {
       	   if(head==NULL) return;
       	   
       	   
       	   if(curr_size==1)
       	   {     
       	     	 Node* temp=head;
       	  	     head=NULL;
       	  	     middle=NULL;
       	  	     delete temp;
       	  	      
       	    }
       	    else if(curr_size==2)
       	      { Node* temp=middle;
       	    	middle=middle->prev;
       	    	head->next=NULL;
       	    	delete temp;
       	     }
       	     else{
       	     	  Node* temp=middle;
       	     	  
       	     	 if(curr_size%2==0)
       	     	   { middle=middle->prev;
       	     	   	 middle->next=temp->next;
       	     	   	 middle->next->prev=middle;
       	     	   }
       	     	 else
       	     	   { 
       	     	   	   middle=middle->next;
       	     	   	   temp->prev->next=middle;
       	     	   	   middle->prev=temp->prev;
       	     	   	
						   
       	     	   }



       	     	  
       	     	
       	       delete temp;	
       	     }
       	     


       	     curr_size--;
       	   
       	    
       }
  	
};

int main() {
MyStack st;
	st.push(11);
	st.push(22);
	st.push(33);
	st.push(44);
	st.push(55);
	st.pop();
	st.pop();
	st.pop();
	cout<<st.findMiddle()<<endl;
	st.deleteMiddle();
	cout<<st.findMiddle()<<endl;
	return 0;
}
 

