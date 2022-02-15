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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        if(root==NULL) return 0;
          long long int maxx=1;
        q.push({root,0});
        while(!q.empty())
        {   
             long long int first=0,last=0;
            int size=q.size();
            long long int minn=q.front().second;
            for(int i=1;i<=size;i++)
            { 
                  TreeNode* curr=q.front().first;
                  long long int index= q.front().second-minn;
                  q.pop();
                
                  if(i==1) first=index;
                  if(i==size) last=index;
                
                  if(curr->left)q.push({curr->left,2*index+1});
                  if(curr->right)q.push({curr->right,2*index+2});
                
             }
            
             maxx=max({maxx,last-first+1});
           
            
        }
        return (int)maxx;
    }
};