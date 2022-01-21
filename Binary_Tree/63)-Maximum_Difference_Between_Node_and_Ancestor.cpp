class Solution {
public:
    int maxx=INT_MIN;
    void helper(TreeNode* root,int curr_max=INT_MIN,int curr_min=INT_MAX)
    {   
         if(root==NULL) return;
        
         if(curr_max!=INT_MIN)
            maxx=max({maxx,abs(curr_max-root->val),abs(curr_min-root->val)});
        
         helper(root->left,max(curr_max,root->val),min(curr_min,root->val));
         helper(root->right,max(curr_max,root->val),min(curr_min,root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
         helper(root);
         return maxx;
        
    }
};