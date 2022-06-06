class Solution {
    struct comp{
        bool operator()(ListNode* a,ListNode* b)
        {
           return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(pq.empty()) return NULL;
        ListNode* head=pq.top();
        ListNode* tail=pq.top();
        pq.pop();
        
        if(head->next)
        pq.push(head->next);
        
        while(!pq.empty())
        {
            tail->next=pq.top();
             pq.pop();
            
            tail=tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return head;
        
        
    }
};

====================================================================================================
====================================================================================================
====================================================================================================

// ---  [Brute_force] Merge first with second,then ans of that with third ,then answer of that with fouth,and so on.................... 
 //   [If each list has n size and we have k lists,Then Complexity will be] O(n*k*k) 

class Solution {  // This is Most Basic Approach
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* head=NULL;  
          if(!l1) return l2;
          if(!l2) return l1;
          if(l1->val<=l2->val)
            {  head=l1;
               l1=l1->next;
            }
          else
           { head=l2;
             l2=l2->next;
           }
          ListNode *curr=head;
          while(l1 && l2)
          {    if(l1->val<=l2->val)
                   {
                    curr->next=l1; l1=l1->next;
                   }
               else
                   {
                     curr->next=l2; l2=l2->next;
                   }
              curr=curr->next;
            
          }
        
        if(l1) curr->next=l1;
        if(l2) curr->next=l2; 
        return head;
       
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
        
    }
};

====================================================================================================
====================================================================================================
====================================================================================================


// Approach 2--> We can use map to store frequency of each ele -- O(n*k*log(n*k)) Time and O(n*k) space for map//
// Changing data of Linkedlist is not recommended[Explaind here in solution bcz we shold know where it fails], Highly avoidable bcz our Solution will not work when we have data as
// --User defined data not int or char//

class Solution {
public:
    map<int,int>mp;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode* curr=lists[i];
            ListNode *nxt;
            while(curr)
            {   ListNode* temp=curr;
                mp[curr->val]++;
                curr=curr->next;
                delete temp;
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        for(auto X:mp)
        {
            for(int i=1;i<=X.second;i++)
            {
                ListNode* temp=new ListNode(X.first);
                prev->next=temp;
                prev=prev->next;
                
            }
            
        }
        return dummy->next;
    }
};

====================================================================================================
====================================================================================================
====================================================================================================



//Approach 3-Using Divide and Conquer  This approach doesn’t require extra space for heap and works in O(nk Log k)//
//-->The idea is to pair up K lists and merge each pair in linear time //
//-->After the first cycle, K/2 lists are left each of size 2*N. After the second cycle, K/4 lists are left each of size 4*N and so on.//
//Repeat the procedure until we have only one list left.//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* head=NULL;  
          if(!l1) return l2;
          if(!l2) return l1;
          if(l1->val<=l2->val)
            {  head=l1;
               l1=l1->next;
            }
          else
           { head=l2;
             l2=l2->next;
           }
          ListNode *curr=head;
          while(l1 && l2)
          {    if(l1->val<=l2->val)
                   {
                    curr->next=l1; l1=l1->next;
                   }
               else
                   {
                     curr->next=l2; l2=l2->next;
                   }
              curr=curr->next;
            
          }
        
        if(l1) curr->next=l1;
        if(l2) curr->next=l2; 
        return head;
       
    }
    
    ListNode* merge_k(vector<ListNode*>& lists,int start,int end)
    {   if(start>end) return NULL;
        if(start==end) return lists[start];
        ListNode* newh;
        int mid=start+(end-start)/2; 
        ListNode* a= merge_k(lists,start,mid);
        ListNode* b= merge_k(lists,mid+1,end);
        newh=mergeTwoLists(a,b);
            
   
     return newh;
         
        
    }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return NULL;
        int start=0,end=lists.size()-1;
        
        return merge_k(lists,start,end);
      
    }
};

