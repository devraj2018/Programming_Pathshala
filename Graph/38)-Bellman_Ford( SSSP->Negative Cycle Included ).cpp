class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
         
        int e=adj.size();
        
        vector<int>dis(V,1e8);
        dis[S]=0;
        
        for(int i=0;i<V-1;i++)
        {
              for(int j=0;j<e;j++)
               {
                  int u=adj[j][0];
                  int v=adj[j][1];
                  int w=adj[j][2];
                  
                  if(dis[u]!=1e8 && dis[u]+w<dis[v])
                      dis[v]=dis[u]+w;
              }
          }
        return dis;
    }
};
