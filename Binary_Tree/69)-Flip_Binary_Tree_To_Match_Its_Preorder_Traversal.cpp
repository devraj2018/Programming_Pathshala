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
    bool ans;
    void helper(TreeNode* root,vector<int>&voyage,int &curr_I,vector<int>&res)
    {
         if(root==NULL || ans==false) return;
         if(curr_I==voyage.size()) return;
        
         if(voyage[curr_I]!=root->val) {
             ans=false;
             return;
         }
        
         curr_I++;
        
         if(root->left && voyage[curr_I]!=root->left->val)
         {
             res.push_back(root->val);
             helper(root->right,voyage,curr_I,res);
             helper(root->left,voyage,curr_I,res);
         }
         else
          {    helper(root->left,voyage,curr_I,res);
               helper(root->right,voyage,curr_I,res);
          }
         
      }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        vector<int>res;
        int curr_I=0;
        ans=true;
        helper(root,voyage,curr_I,res);
       
       
        if(ans) return res;
        
        return {-1};
        
        
    }
};