class Solution {
public:
    bool ans=true;
    void helper(int src,vector<vector<int>>& graph,vector<int>&color,int col)
    {   if(ans==false) return;
         color[src]=col;
         for(auto x:graph[src])
         {
               if(color[x]==-1)
                {   int newc= (col==0)?1:0;
                    helper(x,graph,color,newc);
                }
               else if(color[x]==col)
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
            if(color[i]==-1) helper(i,graph,color,0);
            if(ans==false) return false;
          }
        return ans;
          
    }
};