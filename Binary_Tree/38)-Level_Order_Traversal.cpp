class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {   
             vector<int>v;
             int size=q.size();
             for(int i=0;i<size;i++)
               {   TreeNode* curr=q.front();
                   q.pop();
                   v.push_back(curr->val);
                   if(curr->left) q.push(curr->left);
                   if(curr->right) q.push(curr->right);
               }
              res.push_back(v);
        }
        return res;
        
       
    }
};