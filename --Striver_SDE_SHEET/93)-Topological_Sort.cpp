#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];
      vector<int>Indegree(v,0);
    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
       Indegree[edges[i][1]]++;
     }
   queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(Indegree[i]==0) q.push(i);
        }
        vector<int>res;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            
            for(auto child:adj[curr])
            {
                
                Indegree[child]--;
                 if(Indegree[child]==0) q.push(child);
                
            }
            
        }
        
         if( res.size()==v) return res;
         return {};
}