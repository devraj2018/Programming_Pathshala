/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node *prev;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
              
               int size=q.size();
            for(int i=0;i<size;i++)
            {
                 Node* curr=q.front();
                 q.pop();
                 
                 if(i!=0)
                 {
                     prev->next=curr;
                 }
                 prev=curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
             
        }
        return root;
            
        
        
    }
};