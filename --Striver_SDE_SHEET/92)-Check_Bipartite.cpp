bool dfs(int x,vector<vector<int>> &edges,int n,vector<int>&color,int col)
{
     color[x]=col;
    
     for(int i=0;i<n;i++)
     {
         if(edges[x][i])
         {
              if(color[i]==-1)
              {
                  if(!dfs(i,edges,n,color,col^1))
                      return false;
              }
             else if(color[i]==col) return false;
            
         }
    }
    return true;
    
    
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	
    int n=edges.size();
    vector<int>color(n,-1);
    
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,edges,n,color,0))
                return false;
        }
    }
    return true;
    
    
}