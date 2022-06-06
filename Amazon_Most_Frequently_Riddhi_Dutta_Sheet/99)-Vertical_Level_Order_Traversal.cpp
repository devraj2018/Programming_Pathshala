
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          vector<vector<int>>res; 
         if(root==NULL) return res;
        
        
         unordered_map<int,vector<int>>mp;
         queue<pair<TreeNode*,int>>q;
         int maxx=0,minn=0;
         q.push({root,0});
        
        while(!q.empty())
        {
           int size=q.size();
           unordered_map<int,multiset<int>>temp;
           for(int i=1;i<=size;i++)
           {
                 TreeNode* curr=q.front().first;
                 int vd=q.front().second;
                 q.pop();
            
                 maxx=max(maxx,vd);
                 minn=min(minn,vd);
            
                 temp[vd].insert(curr->val);
            
                 if(curr->left) q.push({curr->left,vd-1});
                 if(curr->right) q.push({curr->right,vd+1});
               
               
           }
           for(auto m:temp)
           {
               for(auto val:m.second)
               {
                   mp[m.first].push_back(val);
               }
           }
        }
        for(int i=minn;i<=maxx;i++)
        {
            res.push_back(mp[i]);
        }
        return res;
        
         
       
         
    }
};