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
    vector<vector<int>>res;
    void helper(TreeNode* root,int sum,int curr_sum,vector<int>&curr_path)
    {
        
         if(root==NULL) return;
        
         curr_sum+=root->val;
         curr_path.push_back(root->val);
        
         if(root->left==NULL && root->right==NULL)
         {
             
             if(curr_sum==sum) res.push_back(curr_path);
             
             curr_path.pop_back();
             return;
             
         }
         
        helper(root->left,sum,curr_sum,curr_path);
        helper(root->right,sum,curr_sum,curr_path);
        
         curr_path.pop_back();
        
        
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr_path;
        
        helper(root,targetSum,0,curr_path);
        return res;
        
    }
};