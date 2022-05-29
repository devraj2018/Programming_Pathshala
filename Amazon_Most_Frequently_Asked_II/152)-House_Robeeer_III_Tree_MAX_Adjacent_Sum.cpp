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
      unordered_map<TreeNode*,int>dp;
      int helper(TreeNode* root)
       {
        if(root==NULL) return 0;
        
        if(dp.find(root)!=dp.end()) return dp[root];
        int take=root->val;
        if(root->left && root->left->left) take+=helper(root->left->left);
        if(root->left && root->left->right) take+=helper(root->left->right);
        if(root->right && root->right->left) take+=helper(root->right->left);
        if(root->right && root->right->right) take+=helper(root->right->right);
        
        int dont_take=0;
        
        dont_take= helper(root->left)+helper(root->right);
        
        return dp[root]=max(take,dont_take);
        
        
        
    }
    int rob(TreeNode* root) {
        return helper(root);
    }
};