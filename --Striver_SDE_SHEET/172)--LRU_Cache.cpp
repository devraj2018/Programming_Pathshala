#include<bits/stdc++.h>
class LRUCache
{
    struct Node{
        int key,value;
        Node* prev;
        Node* next;
        Node(int _k,int _v)
        {
            key=_k;value=_v;
            prev=NULL,next=NULL;
        }
        
    };
public:
    unordered_map<int,Node*>mp;
    Node* head,*tail;
    int capacity;
    LRUCache(int c) {
        head=NULL;tail=NULL;
        capacity=c;
    }
   
   void moveToTail(Node* currnode,int value)
    {
         currnode->value=value;
         
         if(head==tail || currnode==tail) return;
         
         if(head==currnode) //Head NOde
         {
             head=head->next;
             head->prev=NULL;
             
          }
        else{  //SAndwich node
            
            
            currnode->prev->next=currnode->next;
            currnode->next->prev=currnode->prev;
          }
        
             tail->next=currnode;
             currnode->prev=tail;
             tail=tail->next;
             tail->next=NULL;
        
    }
    int get(int key) {
         
        if(mp.find(key)==mp.end()) return -1;
        
        int ans= mp[key]->value;
        moveToTail(mp[key],ans);
        return ans;
        
        
    }
    
    void addToTail(int key,int value)
    {
        
        Node* newnode=new Node(key,value);
        
        mp[key]=newnode;
        
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
            
        }
        
        
        
    }
    void deleteAtHead()
    {
         mp.erase(head->key);
        
         if(head==tail)
         {
             head=NULL;tail=NULL;
             return;
         }
         Node* temp=head;
         head=head->next;
         head->prev=NULL;
         
        delete temp;
        
        
        
    }
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            moveToTail(mp[key],value);
            return;
        }
        
        if(mp.size()==capacity) deleteAtHead();
         addToTail(key,value);
            
        }
};
