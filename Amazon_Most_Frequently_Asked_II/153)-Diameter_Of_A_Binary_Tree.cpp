/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=-1;
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int lh=helper(root->left);
        int rh=helper(root->right);
        
        if(root->left && root->right)
        {
            ans=max(ans,1+lh+rh);
            return 1+max(lh,rh);
        }
        if(root->left)
        {
            return 1+lh;
        }
        
        return 1+rh;
        
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
       int res= helper(root);
        
        if(res>ans) return res-1;
        return ans-1;
    }
};