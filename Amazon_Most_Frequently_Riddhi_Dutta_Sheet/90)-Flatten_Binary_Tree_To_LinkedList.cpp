class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
        
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        
        TreeNode* predecessor=root;
        while(predecessor->right)
        {
            predecessor=predecessor->right;
        }
        predecessor->right=temp;
        
        flatten(root->right);
        
        
        
    }
};