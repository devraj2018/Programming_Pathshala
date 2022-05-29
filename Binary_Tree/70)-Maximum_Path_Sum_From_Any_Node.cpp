
class Solution {
public:
    int ans=INT_MIN;
    
    int sum(TreeNode* root)
    {
         if(root==NULL) return 0;
        
         int lsum=sum(root->left);
         int rsum=sum(root->right);
         
         if(root->left && root->right)
         {
              ans=max({ans,root->val,root->val+lsum,root->val+rsum,root->val+lsum+rsum});
              return max({root->val,root->val+lsum,root->val+rsum});
         }
        
         if(root->left)
         {
              ans=max({ans,root->val,root->val+lsum});
              return max(root->val,root->val+lsum);
         }
        
          ans=max({ans,root->val,root->val+rsum});
          return max(root->val,root->val+rsum);
        
        
        
    }
    int maxPathSum(TreeNode* root) {
        
        sum(root);
        return ans;
        
    }
};