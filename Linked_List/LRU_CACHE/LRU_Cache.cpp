struct Node{
        public:
        int key;int val;
        Node* prev,*next;
        Node(int k,int v) { key=k; val=v; prev=NULL;next=NULL; }
    };
    
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int maxsize,currsize;  Node *head,*tail;
    
    LRUCache(int capacity) {
        maxsize=capacity; currsize=0;  head=NULL;tail=NULL;
    }
    
    void move_To_Tail(Node * node,int val)
    {   node->val=val;  // Also handle Update and move to tail case or move to tail without update
        if(node==tail) return;
        if(node==head) // First node
          {    head=head->next;
               head->prev=NULL;
          }
       else  // Sandwich node
         {  node->prev->next=node->next;
            node->next->prev=node->prev;
         }
        node->prev=tail;  // Inserting after tail
        node->next=NULL;   
        tail->next=node;
        tail=node;
     }
    
    void delete_At_Head()
     {  Node* temp=head;
       head=head->next;
       if(head)  // To handle null pointer exception in case of only one node
           head->prev=NULL;
       else tail=head;   // Means tail set to NULL
       
       delete temp;
       currsize--;
    }
    Node* add_To_Tail(int key,int value)
    {  Node* node=new Node(key,value);
       
       if(tail==NULL)  //If we had empty LL       
        {   head=node;
           tail=node;
        }
     else{
         tail->next=node;
         node->prev=tail;
         tail=node;
         }
    currsize++;
    return node;    // SO that is gets inserted into map    
    }
    int get(int key) {
        int ans;
        if(mp.find(key)==mp.end())  ans=-1;
        else
        {    Node *node=mp[key];
             ans=node->val;
             move_To_Tail(node,node->val);   // Without Update->That's why passing same data for value
        }
        return ans;
      }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            move_To_Tail(mp[key],value); // Update and move to tail
            return;
        }
        
        if(currsize<maxsize) mp[key]=add_To_Tail(key,value);
        else
        {   mp.erase(head->key);
            delete_At_Head();
            mp[key]=add_To_Tail(key,value);
         }
         
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */