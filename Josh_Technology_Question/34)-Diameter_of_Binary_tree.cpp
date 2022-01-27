
class Solution {
public:
    int diameter=0;
    int height(TreeNode* root)
    {
         if(root==NULL) return 0;
        
         int lh=height(root->left);
         int rh=height(root->right);
        
         diameter=max(diameter,lh+rh);
        
         return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return diameter;
    }
};