class LRUCache {
    struct Node{
        int key,value;
        Node* next,*prev;
        Node(int _k,int _val)
           {
            key=_k;value=_val;
            next=NULL;prev=NULL;
           }
     };
public:
     unordered_map<int,Node*>mp;
     Node* head,*tail;
     int curr_size,capacity;
    
    LRUCache(int _capacity) {
        head=NULL,tail=NULL;
        curr_size=0;
        capacity= _capacity;
    }
    
    void move_to_tail(int key,int val)
    {
        mp[key]->value=val;
        Node* curr_node=mp[key];
        if(head==tail || curr_node==tail) return;       // if node is last node
        
        if(curr_node==head)          // If node is first node
        {   head=head->next;
            head->prev=NULL;
        }
        else       // Sandwich node
        {   curr_node->next->prev=curr_node->prev;
            curr_node->prev->next=curr_node->next;
        }
        tail->next=curr_node;          // Inserting at last
        curr_node->prev=tail;
        tail=tail->next;
    }
    
    int get(int key) {
        int ans=-1;
        
        if(mp.find(key)!=mp.end())
           {  ans=mp[key]->value;
              move_to_tail(key,ans);
           }
        return ans;
     }
    void insert_At_Tail(Node* curr_node)
    {
        if(head==NULL)
        {
            head=curr_node;
            tail=curr_node;
            return;
        }
        
        tail->next=curr_node;
        curr_node->prev=tail;
        tail=tail->next;
     }
    void delete_At_Head()
    {    Node* temp=head;
         mp.erase(temp->key);
        if(head==tail)
          {   
              head=NULL;
              tail=NULL;
         }
       else
        {
          head=head->next;
          head->prev=NULL;
        }
     delete temp;
     }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            move_to_tail(key,value);
            return;
        }
        
        if(curr_size<capacity)
        {
             curr_size++;
             Node* curr_node=new Node(key,value);
             mp[key]=curr_node;
             insert_At_Tail(curr_node);         // Inserting at last
         }
        else
          {
             delete_At_Head();
              Node* curr_node=new Node(key,value);
             mp[key]=curr_node;
             insert_At_Tail(curr_node);
        }
 }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */