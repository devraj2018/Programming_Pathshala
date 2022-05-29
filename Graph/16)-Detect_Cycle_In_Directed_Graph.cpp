class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<bool> &vis,vector<bool> &ancestor,vector<int> adj[])
    {     vis[src]=true;
          ancestor[src]=true;
          
          for(auto x: adj[src])
             {
                if(!vis[x])
                    {
                       if(dfs(x,vis,ancestor,adj))
                           return true;
                    }
                 else if(ancestor[x])
                    return true;
            }
          ancestor[src]=false;
          return false;
        
     }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> ancestor(V,false);
        
        
        for(int i=0;i<V;i++)
        {   if(!vis[i])
              {
                  if(dfs(i,vis,ancestor,adj)) return true;
               }
          }
        return false;
    }
};