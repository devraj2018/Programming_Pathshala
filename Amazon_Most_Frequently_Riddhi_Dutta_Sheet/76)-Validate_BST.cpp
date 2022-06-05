class Solution {
public:
    bool helper(TreeNode* root,long long lft,long long rgt)
    {
         if(root==NULL) return true;
        
         if(root->val<=lft || root->val>=rgt) return false;
        
         return helper(root->left,lft,(long long)root->val) && helper(root->right,(long long)root->val,rgt);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return helper(root,LLONG_MIN,LLONG_MAX);
        
    }
};