#include <bits/stdc++.h> 

struct comp{
        bool operator()(Node* a,Node* b)
        {
           return a->data>b->data;
        }
    };
 
 Node* mergeKLists(vector<Node*>& lists) {
        
        priority_queue<Node*,vector<Node*>,comp>pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(pq.empty()) return NULL;
        Node* head=pq.top();
        Node* tail=pq.top();
        pq.pop();
        
        if(head->child)
        pq.push(head->child);
        
        while(!pq.empty())
        {
            tail->child=pq.top();
             pq.pop();
            
            tail=tail->child;
            if(tail->child) pq.push(tail->child);
        }
        return head;
        
        
    }

Node* flattenLinkedList(Node* head) 
{
	vector<Node*>list;
    Node* curr=head;
    while(curr)
    {
        list.push_back(curr);
        curr=curr->next;
    }
    
   
    
    return mergeKLists(list); 
    
}

==============  ANother Approach =================
Node* merge(Node* a,Node* b)
{
    Node* temp=new Node(1);
    Node* res=temp;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<=b->data)
        {
            temp->child=a;
            a=a->child;
            temp=temp->child;
            temp->next=NULL;
        }
        else
        {
            temp->child=b;
            b=b->child;
            temp=temp->child;
            temp->next=NULL;
        }
    }
    if(a!=NULL)
        temp->child=a;
    if(b!=NULL)
        temp->child=b;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
    
    if(head==NULL || head->next==NULL)
        return head;
    head->next=flattenLinkedList(head->next);
    return merge(head,head->next);
}
