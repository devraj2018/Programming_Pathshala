class Solution{
	public:
	 
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

          // Step 3: check for negative-weight cycles.
    // The above step guarantees shortest distances
    // if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }
  
    return false;
        
    }
};