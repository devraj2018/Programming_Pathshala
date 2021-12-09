class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val== p->val || root->val==q->val)
            return root;
        
        TreeNode* lft=lowestCommonAncestor(root->left,p,q);
        TreeNode* rgt=lowestCommonAncestor(root->right,p,q);
        
        if(lft && rgt)
            return root;
        
        if(lft==nullptr) return rgt;
        
        return lft;
        
    }
};