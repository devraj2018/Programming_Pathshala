class Solution
{
    public:
    
   vector<int> verticalOrder(Node *root)
       {
           unordered_map<int,vector<int>>mp;
           int lft=INT_MAX;
           int rgt=INT_MIN;
       
           if(root==NULL) return {};
           queue<pair<int,Node*>>q;
           q.push({0,root});
       
           while(!q.empty())
              {
                 Node* curr=q.front().second;
                 int dis=q.front().first;
                 q.pop();
           
                 lft=min(lft,dis);
                 rgt=max(rgt,dis);
                
                 mp[dis].push_back(curr->data);
                 if(curr->left) q.push({dis-1,curr->left});
                 if(curr->right) q.push({dis+1,curr->right});
              }

             vector<int>res;
             for(int i=lft;i<=rgt;i++)
                {
                   for(auto x:mp[i])
                      {
                          res.push_back(x);
                      }
                }
            return res;
        }
};