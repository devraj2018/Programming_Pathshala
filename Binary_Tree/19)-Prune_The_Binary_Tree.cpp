
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==NULL) return NULL;
        
        root->left= pruneTree(root->left);
        root->right= pruneTree(root->right);
        
        if(root->val==0 && root->left==NULL && root->right==NULL)
            return NULL;
        else return root;
        
        
    }
};