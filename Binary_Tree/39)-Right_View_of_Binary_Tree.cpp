class Solution {
public:
    vector<int>res;
    void helper(TreeNode* root,int level=0)   // Recursive code  
    {       if(root==NULL) return;           //O(1) Space Excluding call stack
     
            if(res.size()==level)
                res.push_back(root->val);
            else if(res.size()>level)
                res[level]=root->val;
            helper(root->left,level+1);
            helper(root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        helper(root);
        return res;
        
    }
};

class Solution
{ public:
     vector<int> rightView(Node *root)  // Level order traversal O(n)space Queue
       {   if(root==NULL) return {};
           vector<int> temp;
       
           queue<Node*> q;
           q.push(root);
            while(!q.empty())
            {  
               int size=q.size();
               for(int i=1;i<=size;i++)
                {  Node* curr=q.front();q.pop();     
                   if(i==size)
                      temp.push_back(curr->data);   // Last Node of every Level
                   if(curr->left) q.push(curr->left);
                   if(curr->right) q.push(curr->right);
                }
             }
       return temp;
    }
};