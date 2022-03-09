
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
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>mp;  // Two corresponding nodes of both linkedlist
        Node* newHead=NULL,*newtail=NULL;
        Node* curr=head;
        while(curr)   // Creating new cloned linkedlist with updating random pointer 
        {
             Node* temp=new Node(curr->val);
             
             if(newHead==NULL)
             {
                 newHead=temp;
                 newtail=temp;
             }
             else
             {
                newtail->next=temp;
                newtail=newtail->next;
             }
             mp[curr]=temp;
             curr=curr->next;
        }
        Node* temp=head;
        curr=newHead;
        while(curr)
        {
             Node* nxtrand=mp[temp->random];  // Accessing corresponding node in new Linkedlist
             curr->random=nxtrand;           //--of a random pointer in old linkedlist
             curr=curr->next;
             temp=temp->next;
       }
        return newHead;
        
        
    }
};