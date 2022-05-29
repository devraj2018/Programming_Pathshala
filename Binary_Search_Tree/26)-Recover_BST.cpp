class Solution {
public:
    vector<pair<TreeNode*,TreeNode*>>res;
    void helper(TreeNode* root,TreeNode*& prev)
    {
         if(root==NULL) return;
        
         helper(root->left,prev);
        
         if(prev && prev->val > root->val)
         {
             res.push_back({prev,root});
         }
        prev=root;
        
        helper(root->right,prev);
       
       
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        helper(root,prev);
        
        if(res.size()==1)
        {
             swap(res[0].first->val,res[0].second->val);
             return;
        }
         swap(res[0].first->val,res[1].second->val);
        
    }
};