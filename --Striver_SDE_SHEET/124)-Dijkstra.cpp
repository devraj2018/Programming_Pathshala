vector<int> dijkstra(vector<vector<int>> &vec, int v, int edges, int source) {
   
    vector<pair<int,int>>adj[v];
    
    for(int i=0;i<vec.size();i++)
    {
       int x=vec[i][0];
       int y=vec[i][1];
       int w=vec[i][2];
        
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    
    vector<int>dis(v,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dis[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
         int u=pq.top().second;
         int w=pq.top().first;
         pq.pop();
        
          
        
        for(auto &p:adj[u])
        {
            int v=p.first;
            int d=p.second;
            
            if(dis[u]+d<dis[v])
            {
                dis[v]=dis[u]+d;
                pq.push({dis[v],v});
            }
        }
          
        
    }
    return dis;
    
    
    
    
}
