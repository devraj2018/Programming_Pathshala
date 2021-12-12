class Solution {
public:
    int n=0;  // To store Size of Linkedlist
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
         while(curr)
         {  nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            n++;
          }
         return prev;
       }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        if(head==NULL) return res;
        head=reverseList(head);
        res.resize(n,0);
        stack<int>s;
        
        for(int i=n-1;i>=0;i--)
        {  while(!s.empty() && s.top()<=head->val) s.pop();
           
            if(!s.empty()) res[i]=s.top();
            s.push(head->val);
            head=head->next;
        }
        return res;
       
    }
};