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
        q.push({root,0});
        long long maxx=0;
        
        while(!q.empty())
        {
            
            int size=q.size();
            long long lft,rgt;
            long long minn=q.front().second;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                long long dis=q.front().second-minn;
                q.pop();
                
                if(i==0) lft=dis;
                if(i==size-1) rgt=dis;
                
                if(curr->left) q.push({curr->left,2*dis+1});
                if(curr->right) q.push({curr->right,2*dis+2});
                
            }
            maxx=max(maxx, rgt-lft+1);
            
            
        }
        return maxx;
        
    }
};