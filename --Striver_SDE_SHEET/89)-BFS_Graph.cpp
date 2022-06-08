#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<set<int>>adj(vertex);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].insert(edges[i].second);
         adj[edges[i].second].insert(edges[i].first);
        
    }
    
    queue<int>q;
    
    vector<bool>visited(vertex,false);
    
    vector<int>res;
    
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]) continue;
       
        q.push(i);
        visited[i]=true;
      while(!q.empty())
      {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for(auto x:adj[curr])
        {
            if(!visited[x]) 
            {
                q.push(x);
                visited[x]=true;
            }
            
        }
    }
    }
    return res;
}