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
    TreeNode* helper(vector<int>& postorder,int &currI,int start,int end)
    {
         if(end>start) return NULL;
        
         int mid=mp[postorder[currI]];
         TreeNode* newroot=new TreeNode(postorder[currI]);
         currI--;
         newroot->right=helper(postorder,currI,start,mid+1);
         newroot->left=helper(postorder,currI,mid-1,end);
         return newroot;
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size()==0) return NULL;
        
        int n=inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        int currI=n-1;
        return helper(postorder,currI,n-1,0);
        
    }
};