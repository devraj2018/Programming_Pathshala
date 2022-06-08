#include<bits/stdc++.h>
void dfs(int x, vector<set<int>>&adj,vector<bool>&vis,vector<int>&curr)
{
     vis[x]=true;
     curr.push_back(x);
     
     for(auto child:adj[x])
     {
         if(!vis[child])
         {
             dfs(child,adj,vis,curr);
         }
     }
    
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   vector<set<int>>adj(V);
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].insert(edges[i][1]);
         adj[edges[i][1]].insert(edges[i][0]);
        
    }
        vector<bool>vis(V,false);
    vector<vector<int>>res;
    
      for(int i=0;i<V;i++)
      {
         if(!vis[i])
         {   vector<int>curr;
             dfs(i,adj,vis,curr);
             res.push_back(curr);
         }
          
      }
     
    return res;
}