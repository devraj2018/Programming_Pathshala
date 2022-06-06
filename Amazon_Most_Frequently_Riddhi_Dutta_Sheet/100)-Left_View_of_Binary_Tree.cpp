
class Solution {
public:
    vector<int>res;
    void helper(TreeNode* root,int level)
    {
         if(root==NULL) return;
        
         if(res.size()==level) res.push_back(root->val);
         
        
         helper(root->left,level+1);
         helper(root->right,level+1);
        
     }
    vector<int> leftSideView(TreeNode* root) {
        helper(root,0);
        return res;
        
    }
};