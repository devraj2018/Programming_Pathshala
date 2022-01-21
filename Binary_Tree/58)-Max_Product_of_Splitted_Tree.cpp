 
class Solution {
public:
    long long total_sum=0,maxx=LLONG_MIN;
    void sum_helper(TreeNode* root)
      {  if(root==NULL) return;
         total_sum+= (long long)root->val;
         sum_helper(root->left);
         sum_helper(root->right);
        }
      long long helper(TreeNode* root)          // Bottom to Up wala traversal
       {  
            if(root==NULL) return 0;
            long long sum= helper(root->left) + helper(root->right) + (long long)root->val;
            
            maxx=max(maxx,sum*(total_sum-sum));
            return sum;
       }
    int maxProduct(TreeNode* root) {
        sum_helper(root);
        helper(root);
        int mod=1e9+7;
        
        int ans= (int)(maxx%mod);
        return ans;
        
        
    }
};