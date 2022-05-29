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
    long long ans=INT_MIN;
    
    long long totalSum(TreeNode* root)
    {
        if(!root) return 0;
        
        long long lsum=totalSum(root->left);
        long long rsum=totalSum(root->right);
        
        return (long long)root->val+lsum+rsum;
    }
    int helper(TreeNode* root,long long sum)
    {
        
         if(root==NULL) return 0;
        
         long long lsum=helper(root->left,sum);
         long long rsum=helper(root->right,sum);
        
         ans=max(ans,(sum- (root->val+lsum+rsum))*(root->val+lsum+rsum));
        
        return (long long)root->val+lsum+rsum;
    }
    int maxProduct(TreeNode* root) {
        
        long long sum=totalSum(root);
        
        helper(root,sum);
        long long mod=1e9+7;
        ans=ans%mod;
        
        return (int)ans;
        
        
    }
};