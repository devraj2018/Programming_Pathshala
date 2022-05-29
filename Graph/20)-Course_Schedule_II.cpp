
// --------------- Khan's Algorithm -----------------       //
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        vector<int>adj[n];
        vector<int>res;
        queue<int>q;
        for(int i=0;i<pre.size();i++)
        {   adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
         }
        for(int i=0;i<n;i++)
        {  if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {   int curr=q.front();
            q.pop();
            res.push_back(curr);
            
            for(auto x:adj[curr])
               {
                   
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
               
                }
          }
        
        if(res.size()==n) return res;
        return {};
     }
};