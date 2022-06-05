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
    int res;
    int helper(TreeNode* root)
    {
          if(root==NULL) return INT_MIN;
        
          if(root->left==NULL && root->right==NULL)
          {
              res=max(res,root->val);
              return root->val;
          }
        
          int leftsum=helper(root->left);
          int rightsum=helper(root->right);
        
          if(root->left && root->right)
          {
              res=max({res,root->val,root->val+leftsum,root->val+rightsum,root->val+leftsum+rightsum});
              return max({root->val,root->val+leftsum,root->val+rightsum});
              
          }
        
          if(root->left)
          {
              res=max({res,root->val,root->val+leftsum});
              return max(root->val,root->val+leftsum);
          }
        
          res=max({res,root->val,root->val+rightsum});
          return max(root->val,root->val+rightsum);
          
   }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        helper(root);
        return res;
        
    }
};