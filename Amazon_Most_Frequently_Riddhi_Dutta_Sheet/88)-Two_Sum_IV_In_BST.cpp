class Solution {
public:
    unordered_map<int,int>mp;
    bool ans;
    
    void helper(TreeNode* root,int k)
    {
        if(!root || ans) return;
        
        helper(root->left,k);
        
        if(mp.find(k-root->val)!=mp.end()){
            ans=true;
            return;
        }
        mp[root->val]++;
        
        helper(root->right,k);
        
        
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        ans=false;
        helper(root,k);
        return ans;
    }
};