class Solution {
public:
    bool isValidBST(TreeNode* root,long long left=LLONG_MIN,long long right=LLONG_MAX) {
        
        if(root==NULL) return true;
        
        if(root->val >right || root->val < left) return false;
        
        return isValidBST(root->left,left,(long long)root->val-1) &&isValidBST(root->right,(long long)root->val+1,right) ;
        
    }
};