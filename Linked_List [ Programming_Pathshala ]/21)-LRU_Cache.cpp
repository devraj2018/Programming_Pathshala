class LRUCache {
    struct Node{
        int key,val;
        Node* prev,*next;
        Node(int k,int v)
        {
            key=k;val=v;
            prev=NULL,next=NULL;
        }
     };
public:
    Node* head,*tail;
    int curr_size,max_size;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        max_size=capacity;
        curr_size=0;
        head=NULL,tail=NULL;
    }
    
   
    
    void move_to_tail(Node* node,int value)
    {
         node->val=value;
         if(node==tail) return;
          
         if(head==node)
         {
              head=head->next;
              head->prev=NULL;
             
         }
        else
        {
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
        
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
    Node* add_to_tail(int key,int value)
    {
        Node* newnode=new Node(key,value);
         curr_size++;
        if(tail==NULL)
        {  
            head=newnode;
            tail=newnode;
            return newnode;
        }
        
        
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        return newnode;
        
    }
    void delete_at_head()
    {
        Node* temp=head;
        head=head->next;
        curr_size--;
        if(head==NULL)
        {
            head=NULL;
            tail=NULL;
            return;
        }
        head->prev=NULL;
        delete temp;
        
        
        
    }
     int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        
        int ans;
        ans=mp[key]->val;
        
        move_to_tail(mp[key],ans);
        return ans;
        
    }
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
          {
             move_to_tail(mp[key],value);
             return;
          }
        
         if(curr_size<max_size) mp[key]=add_to_tail(key,value);
         else
         {
            mp.erase(head->key);
            delete_at_head();
            mp[key]=add_to_tail(key,value);
         }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */