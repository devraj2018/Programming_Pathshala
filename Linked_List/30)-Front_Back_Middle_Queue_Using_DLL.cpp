class Node{
    public:
    int val;   Node*prev;   Node *next;
     Node(int value){ val=value; next=NULL;prev=NULL; }
};

class FrontMiddleBackQueue {
public:
    Node* head,*tail;
    
    FrontMiddleBackQueue() {
       head=NULL; tail=NULL; 
        
    }
      void pushFront(int val) {
        Node* node=new Node(val);
        if(head==NULL)
        { head=node;
          tail=node;
        }
        
        else
        {   node->next=head;
            head->prev=node;
            head=node;
         }
        
   }
    Node* findMiddle(Node* head,bool &isMiddle)
    {
        Node* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL) isMiddle=false;
        return slow;
     }
    void pushBack(int val) {
        Node* node=new Node(val);
        if(head==NULL)
        { head=node;
          tail=node;
        }
        else
        {   tail->next=node;
            node->prev=tail;
            tail=node;
         }
        
      }
    
    void pushMiddle(int val) {
        Node* node=new Node(val);
         
        if(head==NULL)
        {
            head=node;
            tail=node;
            return;
        }
        bool isMiddle=true;
        Node* slow=findMiddle(head,isMiddle);
        if(slow->prev==NULL)  // Operation to be performed on head node
        {
            node->next=head;
            head->prev=node;
            head=node;
        }
        else
        {
            Node* previous=slow->prev;
            node->next=slow;
            slow->prev=node;
            previous->next=node;
            node->prev=previous;
        }
       
        
    }
    
    
    
    int popFront() {
        if(head==NULL)return -1;
        int ans=head->val;
        Node* temp=head;
        head=head->next;
        
        if(head)
            head->prev=NULL;
        else
            tail=head;
        delete temp;
         
        return ans;
        
    }
    
    int popMiddle() {
        if(head==NULL) return -1;
        int ans;
        bool isMiddle=true;
        Node* slow=findMiddle(head,isMiddle);
        
        if(slow==head) // Single node
        {
            ans=slow->val;
            delete slow;
            head=NULL;tail=NULL;
            return ans;
        }
        
        if(slow==tail)  // Operation to be performed on head node
        {   Node* temp=head;
            head=head->next;
            head->prev=NULL;
            ans=temp->val;
            delete temp;
        }
        else
        {   if(!isMiddle) slow=slow->prev;       
             ans=slow->val;
            slow->prev->next=slow->next;
           slow->next->prev=slow->prev;
           delete slow;
           
        }
         
        return ans;
        
    }
    
    int popBack() {
        if(tail==NULL) return -1;
        int ans=tail->val;
        
        Node* temp=tail;
       tail=tail->prev;
        
        
        if(tail)
            tail->next=NULL;
        else
            head=tail;
       delete temp;
        
        return ans;
        
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */