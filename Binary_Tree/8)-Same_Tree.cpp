class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        
         if(root1==NULL || root2==NULL) return false;
        
        return ((root1->val==root2->val) && isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right) );
     
        
    }
};