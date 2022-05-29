/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        
        Node* currA=head;
        Node* dummy=new Node(0);
        Node* tail=dummy;
        
        while(currA)
        {
            tail->next=new Node(currA->val);
            tail=tail->next;
            mp[currA]=tail;
            currA=currA->next;
        }
        currA=head;
         Node* currB=dummy->next;
        
        while(currA)
        {
            currB->random=mp[currA->random];
              currA=currA->next;
              currB=currB->next;
        }
        return dummy->next;
        
    }
};