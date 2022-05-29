class Solution {
public:
    void helper(TreeNode* root,int &curr_sum)
    {  if(root==NULL) return;
       
       helper(root->right,curr_sum);
       curr_sum+= root->val;
       root->val=curr_sum;   
       helper(root->left,curr_sum);
       
       
       
    }
    TreeNode* convertBST(TreeNode* root) {
        int curr_sum=0;
        helper(root,curr_sum);
        return root;
        
    }
};