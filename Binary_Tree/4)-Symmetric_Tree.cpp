class Solution {
public:
    bool Symmetric(TreeNode* root1,TreeNode* root2)
    {  
         if(root1==NULL && root2==NULL) return true;
        
         if(root1==NULL || root2==NULL) return false;
        
        return ((root1->val==root2->val) && Symmetric(root1->left,root2->right) && Symmetric(root1->right,root2->left) );
        
        
        
        
    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root->left && !root->right)
            return true;
        
        
        return Symmetric(root->left,root->right);
        
    }
};