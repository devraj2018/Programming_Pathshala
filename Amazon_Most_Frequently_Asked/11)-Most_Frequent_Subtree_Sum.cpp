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
    int maxx=0;
    unordered_map<int,int>mp;
    int helper(TreeNode* root)
    {
         if(root==NULL) return 0;
        
        
         int l=helper(root->left);
         int r=helper(root->right);
         
         int sum=root->val+l+r;
         mp[sum]++;
         maxx=max(maxx,mp[sum]);
        
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
         vector<int>res;
       
        for(auto x:mp)
        { 
              if(x.second==maxx)
                  res.push_back(x.first);
            
        }
        return res;
        
    }
};