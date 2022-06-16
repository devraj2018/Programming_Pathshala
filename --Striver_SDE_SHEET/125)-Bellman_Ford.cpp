int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &adj) {
    
    vector<int>dis(n+1,1000000000);
        dis[src]=0;
        
        for(int i=0;i<n-1;i++)
        {
              for(int j=0;j<m;j++)
               {
                  int u=adj[j][0];
                  int v=adj[j][1];
                  int w=adj[j][2];
                  
                  if(dis[u]!=1000000000 && dis[u]+w<dis[v])
                      dis[v]=dis[u]+w;
              }
          }
        return dis[dest];
    
    
}