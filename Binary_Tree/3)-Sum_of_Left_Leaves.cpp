class Solution {
public:
    int ans=0;
    void sum(TreeNode* root)
    {
        if(root==NULL) return;
        
         if(root->left && root->left->left==NULL && root->left->right==NULL )
             ans+= root->left->val;
         sum(root->left);
         sum(root->right);
     
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum(root);
        return ans;
        
    }
};