class Solution {
public:
    void helper(TreeNode* root, int &k,int &ans)
    {
        if(root==NULL || ans!=-1) return;
        
        helper(root->left,k,ans);
        
        k--;
        if(k==0){
            ans=root->val;
            return;
        }
        
        
        helper(root->right,k,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        
        int ans=-1;
        helper(root,k,ans);
        return ans;
    }
};