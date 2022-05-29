
             // ---   O(n) SPace using hashing-------//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return NULL;
        
        unordered_map<Node* ,Node*>mp;
        
        Node* curr1=head;
        Node* newhead=NULL,*tail=NULL;
        
        while(curr1)
        {
             Node* newnode=new Node(curr1->val);
             mp[curr1]=newnode;
            
             curr1=curr1->next;
            
             if(tail==NULL)
               {
                 newhead=newnode;
                 tail=newnode;
               }
            else
              {
                tail->next=newnode;
                tail=tail->next;
              }
       }
       
       curr1=head;
        Node* curr2=newhead;
        while(curr1)
        {
             curr2->random=mp[curr1->random];
            
             curr1=curr1->next;
             curr2=curr2->next;
        }
        return newhead;
        
    }
};


=============================================================================================
=============================================================================================
=============================================================================================






class Node {
public:
    int val; Node* next; Node* random;
    
    Node(int _val) {  val = _val; next = NULL; random = NULL;
    }
};
                 //.  --O(1) Space Most Optimized---   // 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node *prev=NULL,*nxt;
        Node* curr=head;
        int prevdata;
        while(curr)
        { 
             if(prev==NULL)
             {   prev=curr;
                 prevdata=curr->val;
                 curr=curr->next;
                 continue;
             }
            
            Node* temp= new Node(prevdata);
            temp->next=curr;
            prev->next=temp;
           
            prevdata=curr->val;
            prev=curr;
            curr=curr->next;
       }
        prev->next= new Node(prevdata);
        
        curr=head;
        while(curr)
        {  
            if(curr->random==NULL)
                curr->next->random=NULL;
            else
            curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node* curr1=head,*head1=head,*head2=head->next,*curr2=head->next;
        while(curr1)
        {
            Node* nxt=curr2->next;
            if(nxt==NULL)
            {
                curr1->next=nxt;
                break;
            }
            curr2->next=nxt->next;
            curr2=curr2->next;
            curr1->next=nxt;
            curr1=curr1->next;
        
            
        }
        head=head1;
        return head2;
      }
};

  