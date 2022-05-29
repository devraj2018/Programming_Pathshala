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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        int minn=INT_MAX;
        int maxx=INT_MIN;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        unordered_map<int,vector<int>>mp;
        
        unordered_map<int,multiset<int>>temp;
        while(!q.empty())
        {
              temp.clear();
              int size=q.size();
              for(int i=0;i<size;i++)
               {
                  TreeNode* curr=q.front().first;
                  int vh=q.front().second;
                  minn=min(minn,vh);
                  maxx=max(maxx,vh);
                  q.pop();
                  
                  temp[vh].insert(curr->val);
                  
                  if(curr->left) q.push({curr->left,vh-1});
                  if(curr->right) q.push({curr->right,vh+1});
             }
            
            for(auto h:temp)
            {
                for(auto ele:h.second)
                {
                    mp[h.first].push_back(ele);
                }
                
            }
            
        }
        vector<vector<int>>res;
        for(int i=minn;i<=maxx;i++)
        {
            res.push_back(mp[i]);
        }
        return res;
        
    }
};