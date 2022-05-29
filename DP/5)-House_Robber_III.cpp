class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int take=root->val;
        
        if(root->left && root->left->left) take+=helper(root->left->left);
        if(root->left && root->left->right) take+=helper(root->left->right);
        if(root->right && root->right->left) take+=helper(root->right->left);
        if(root->right && root->right->right) take+=helper(root->right->right);
        
        int non_take= helper(root->left)+helper(root->right);
        
        
        return mp[root]=max(take,non_take);
        
    }
    int rob(TreeNode* root) {
        
        return helper(root);
         
    }
};