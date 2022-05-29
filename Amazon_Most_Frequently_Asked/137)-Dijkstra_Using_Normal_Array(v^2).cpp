class Solution
{  public:
 
     int minSource(vector<int>&dis,vector<bool>&processed)
       {
           int answer;
           int mindis=INT_MAX;
         
           for(int i=0;i<dis.size();i++)
               {
                  if(dis[i]<mindis && processed[i]==false)
                    {
                      answer=i;
                      mindis=dis[i];
                    }
               }
          return answer;
        
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         vector<int>dis(V,INT_MAX);
         vector<bool>processed(V,false);
         
         dis[S]=0;
         
         for(int i=0;i<V-1;i++)
             {
                int u=minSource(dis,processed);
                processed[u]=true;
               
                for(auto vec:adj[u])
                     {
                         int v=vec[0];
                         int w=vec[1];
                         if(dis[u]+w<dis[v]) dis[v]=dis[u]+w;
                    }
             }
         return dis;
      
      
    }
};