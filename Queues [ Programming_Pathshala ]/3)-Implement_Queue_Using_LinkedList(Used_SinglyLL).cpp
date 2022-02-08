struct Node{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class Queue {
public:
    
       Node* head,*tail;
       Queue() {
                 head=NULL,tail=NULL;
               }

        bool isEmpty() 
                {
                     if(head==NULL) return true;
                     return false;
                }

        void enqueue(int data)
               {
                   Node* newNode= new Node(data);
                  if(head==NULL)
                     {
                       head=newNode;
                       tail=newNode;
                      }
                  else
                    {
                       tail->next=newNode;
                       tail=newNode;
                    }
                 }

         int dequeue() {
        
                 if(head==NULL) return -1;
                  int ans=head->data;
                   if(head==tail)
                       {    
                          head=NULL;
                         tail=NULL;
                        }
                      else
                     {
                         Node* temp =head;
                         head=head->next;
            
                        delete temp;
            
                    }
                   return ans;
        
                }

    int front() {
       if(head==NULL) return -1;
       return head->data;
    }
};