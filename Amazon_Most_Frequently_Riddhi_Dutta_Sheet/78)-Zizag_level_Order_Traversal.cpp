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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>res;
        if(root==NULL) return res;
        
        queue<TreeNode*>q;
        q.push(root);
        bool rev=false;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                
                if(rev) temp[size-i-1]=curr->val;
                else temp[i]=curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
             }
            rev=!rev;
            res.push_back(temp);
            
        }
        return res;
        
        
    }
};