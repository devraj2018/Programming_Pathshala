
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

               // ---   O(n) SPace using hashing-------//

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*>child;
        Node* curr=head;
        Node* newhead=NULL,*prev=NULL;
        
        while(curr)
           {
               Node* newnode=new Node(curr->val);
               child[curr]=newnode;
               
               if(newhead==NULL)  newhead=newnode;
               else prev->next=newnode;
            
               prev=newnode;
               curr=curr->next;
          }
        
        curr=head;
        Node* newlistcurr=newhead;
        
        while(curr)
            {
                Node* rand= curr->random;
                Node* newlistrand= child[rand];
                newlistcurr->random=newlistrand;
                curr=curr->next;
                newlistcurr=newlistcurr->next;
             }
        return newhead;
     }
};