class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<int>adj[],vector<bool>&vis,vector<int>&res)
    {
     vis[src]=true;
     res.push_back(src);
      for(auto x:adj[src])
        { 
           if(!vis[x]) dfs(x,adj,vis,res);
       }
     }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vector<int>res;
      vector<bool>vis(V,false);
      
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
             dfs(i,adj,vis,res);
      }
      return res;
    }
};