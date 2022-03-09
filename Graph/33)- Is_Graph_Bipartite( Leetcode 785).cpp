class Solution {
public:
    bool ans=true;
    
    void dfs(vector<vector<int>>& graph,int src, vector<int>&color,int clr )
    {
         if(ans==false) return;
         color[src]=clr;
        
         for(auto neighbour: graph[src])
         {
              if(color[neighbour]==-1)
              {
                  dfs(graph,neighbour,color,!clr);
              }
             else if(color[neighbour]==clr)
             {
                 ans=false;
                 return;
             }
             
         }
         
         
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
             if(color[i]==-1)
             {
                 dfs(graph,i,color,0);
                 if(ans==false) return false;
             }
            
        }
        return true;
        
        
        
    }
};