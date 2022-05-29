
class Solution {
public:
    bool SameTree(TreeNode* root, TreeNode* subRoot)
    {
         if(root==NULL && subRoot==NULL) return true;
         if(root==NULL || subRoot==NULL) return false;
         return (root->val==subRoot->val) && SameTree(root->left,subRoot->left) &&SameTree(root->right,subRoot->right);
        
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
         if(root==NULL) return false;
         bool ans=false;
         if(root->val==subRoot->val)  ans= SameTree(root,subRoot);
         return ans || isSubtree(root->left,subRoot) ||isSubtree(root->right,subRoot);
        
        
    }
};