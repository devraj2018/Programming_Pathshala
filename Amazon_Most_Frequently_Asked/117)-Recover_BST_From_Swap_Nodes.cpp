
class Solution {
public:
    vector<pair<TreeNode*,TreeNode*>>vec;
    TreeNode* prev;
    void helper(TreeNode* root)
    {
        if(!root) return;
        
        helper(root->left);
        
        if(prev!=NULL && prev->val>root->val)
        {
            vec.push_back({prev,root});
        }
        prev=root;
        helper(root->right);
        
    }
    void recoverTree(TreeNode* root) {
       prev=NULL; 
        
        helper(root);
    
       if(vec.size()==1)
           swap(vec[0].first->val,vec[0].second->val);
        else
            swap(vec[0].first->val,vec[1].second->val);
    }
};