//  O(V * logV)    Priority Queue
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       vector<int>dis(V,INT_MAX);
       vector<bool> processed(V,false);
       dis[S]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,S});
        
       while(!pq.empty())
         {
              int u= pq.top().second;
              processed[u]=true;
              pq.pop();
            
             for(auto neighbour: adj[u])
                 {
                   int v=neighbour[0];
                   int w=neighbour[1];
                  
                   if(processed[v]==false && dis[u]+w<dis[v])
                      {  dis[v]=w+dis[u];
                         pq.push({dis[v],v});
                      }
                 }
          }
       return dis;
    }
};



class Solution           // Simply Method O(V * V)
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int minimum( vector<int>&dis, vector<bool>&processed,int V)
    {
         int minn=INT_MAX;
         int ele;
         
         for(int i=0;i<V;i++)
         {
             if(processed[i]==false && dis[i]<minn)
             {
                 minn=dis[i];
                 ele=i;
             }
         }
         return ele;
     }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       vector<int>dis(V,INT_MAX);
       
       vector<bool> processed(V,false);
       
       dis[S]=0;
       
       for(int i=0;i<V-1;i++)
       {
            int u= minimum(dis,processed,V);
            processed[u]=true;
            
            for(auto neighbour: adj[u])
            {
                int v=neighbour[0];
                int w=neighbour[1];
                
                if(dis[u]!=INT_MAX && dis[u]+w <dis[v])
                {
                    dis[v]=w+dis[u];
                }
            }
           
           
           
       }
       return dis;
    }
};


