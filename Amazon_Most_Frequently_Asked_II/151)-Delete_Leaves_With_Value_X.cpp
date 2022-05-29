
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        if(root==NULL) return NULL;
        
        root->left=removeLeafNodes(root->left,t);   // This is important
        root->right=removeLeafNodes(root->right,t);
        
        if(root->left==NULL && root->right==NULL && root->val==t)
        {
            return NULL;
        }
        return root;
    }
};