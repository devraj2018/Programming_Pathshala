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
    unordered_map<int,int>mp;
    TreeNode* helper(vector<int>& preorder,int &currI,int start,int end)
    {
         if(start>end) return NULL;
        
         int mid=mp[preorder[currI]];
         TreeNode* newroot=new TreeNode(preorder[currI]);
         currI++;
         newroot->left=helper(preorder,currI,start,mid-1);
         newroot->right=helper(preorder,currI,mid+1,end);
         return newroot;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()==0) return NULL;
        
        int n=inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        int currI=0;
        return helper(preorder,currI,0,n-1);
        
    }
};