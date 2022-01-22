class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, vector<bool>&vis, vector<int> adj[],int par)
    {
          vis[src]=true;
          for(auto x:adj[src])
             {
                if(!vis[x])
                   {
                      if(dfs(x,vis,adj,src)) return true;
                   }
                else if(x!= par)
                   return true;
          }
          return false;
       
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++)
        {
             if(!vis[i])
              {
                  if(dfs(i,vis,adj,-1))
                    return true;
              }
            
        }
        return false;
    }
};