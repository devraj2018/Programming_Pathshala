class Solution {
public:
   void helper(TreeNode* root,int targetSum, int curr_sum, bool &ans)
    {      if(root==NULL)  return;
           curr_sum+= root->val;
             if(root->left==NULL && root->right==NULL)
                 {
                    if(targetSum==curr_sum)
                        ans=true;
                    return;
                 }
           helper(root->left,targetSum,curr_sum,ans);
           helper(root->right,targetSum,curr_sum,ans);
     }
    bool hasPathSum(TreeNode* root, int targetSum) {
         bool ans=false;
         int curr_sum=0;
         helper(root,targetSum, curr_sum,ans);
         return ans;
   }
};