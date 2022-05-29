class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int src,int color,vector<int>&col)
    {    
        col[src]=color;
        
        for(auto child:graph[src])
           {
               if(col[child]==-1)
                 {
                    if(dfs(graph,child,color^1,col)==false) return false;
                 }
                else if(col[child]==color) return false;
           }
        return true;
    }

     bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
          {   if(col[i]==-1)
                 {
                      if(dfs(graph,i,0,col)==false) return false;
                 } 
          }
        return true;
        
    }
};