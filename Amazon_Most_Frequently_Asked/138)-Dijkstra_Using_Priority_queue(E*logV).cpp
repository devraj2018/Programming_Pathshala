class Solution
{
	public:
	 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>distance(V,INT_MAX);
        distance[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         pq.push({0,S});
        
        while(!pq.empty())
            {
              int u=pq.top().second;
              pq.pop();
              
              for(auto vec:adj[u])
              {
                  int v=vec[0];
                  int weight=vec[1];
                  
                  if(distance[u]+weight<distance[v])
                  { 
                      
                      distance[v]=distance[u]+weight;
                      pq.push({distance[v],v});
                      
                  }
                  
              }
             
        }
        return distance;
    }
};