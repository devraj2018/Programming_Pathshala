
class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node* currA=head;
        
         Node* dummy=new Node(0);
         Node* tail=dummy;
        
        unordered_map<Node*,Node*>mp;
        while(currA)
        {
            tail->next=new Node(currA->val);
            mp[currA]=tail->next;
            currA=currA->next;
            tail=tail->next;
        }
        Node* currB=dummy->next;
        currA=head;
        while(currA)
        {
             currB->random= mp[currA->random];
             currA=currA->next;
             currB=currB->next;
            
        }
        return dummy->next;
        
    }
};