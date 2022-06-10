#include<bits/stdc++.h>
bool isCycle(int x,vector<bool>&visited,int par,vector<int>adj[])
{
    
    visited[x]=true;
    
    for(auto child:adj[x])
    {
        if(visited[child]==false)
           { if( isCycle(child,visited,x,adj))
                 return true;
           }
        else if(child!=par) 
            return true;
    }
    return false;
    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false && isCycle(i,visited,-1,adj))
            return "Yes";
    }
    return "No";
}
