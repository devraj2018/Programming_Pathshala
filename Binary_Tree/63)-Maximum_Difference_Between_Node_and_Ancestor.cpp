class Solution {
public:
    int ans=INT_MIN;
    
    void helper(TreeNode* root,int minn,int maxx)
    {
         if(root==NULL) return;
        
         if(minn!=INT_MAX)
         {
             ans=max({ans,abs(root->val-minn),abs(root->val-maxx)});
         }
        
        helper(root->left,min(root->val,minn),max(maxx,root->val));
        helper(root->right,min(root->val,minn),max(maxx,root->val));
        
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        helper(root,INT_MAX,INT_MIN);
        return ans;
        
    }
};