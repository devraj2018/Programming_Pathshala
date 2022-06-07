/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void buildpar(TreeNode* root,TreeNode* par)
    {
        if(!root) return;
        
        parent[root]=par;
        buildpar(root->left,root);
        buildpar(root->right,root);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        buildpar(root,NULL);
        unordered_map<TreeNode*,int>visited;
        
        queue<TreeNode*>q;
        q.push(target);
        visited[target]++;
         vector<int> res;
        while(!q.empty())
        {
             int size=q.size();
             if(k==0)
             {
                 for(int i=1;i<=size;i++)
                 {
                     res.push_back(q.front()->val);
                     q.pop();
                     
                 }
                 return res;
             }
             k--;
            
             for(int i=1;i<=size;i++)
             {
                  TreeNode* curr=q.front();
                  q.pop();
                 
                  if(curr->left && visited.find(curr->left)==visited.end())
                  {
                      q.push(curr->left);
                      visited[curr->left]++;
                  }
                 
                 if(curr->right && visited.find(curr->right)==visited.end())
                  {
                      q.push(curr->right);
                      visited[curr->right]++;
                  }
                 
                 if(parent[curr] && visited.find(parent[curr])==visited.end())
                  {
                      q.push(parent[curr]);
                      visited[parent[curr]]++;
                  }
                 
            }
            
       }
        return res;
            
        
    }
};