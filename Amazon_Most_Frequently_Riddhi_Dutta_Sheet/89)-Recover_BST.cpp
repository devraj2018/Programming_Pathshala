/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<pair<TreeNode*,TreeNode*>>vec;
    
    void helper(TreeNode* root,TreeNode* &prev)
    {
         if(!root) return;
        
        helper(root->left,prev);
        
        if(prev && prev->val>root->val)
        {
            vec.push_back({prev,root});
        }
        prev=root;
        helper(root->right,prev);
        
    }
    void recoverTree(TreeNode* root) {
        
        if(root==NULL) return;
        TreeNode* prev=NULL;
        helper(root,prev);
        
        if(vec.size()==1)
        {
            swap(vec[0].first->val,vec[0].second->val);
        }
        else
        {
            swap(vec[0].first->val,vec[1].second->val);
        }
        
        
    }
};