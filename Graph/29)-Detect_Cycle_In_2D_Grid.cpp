class Solution {
public:
     vector<vector<int>>visited;
     bool ans;
     int row,col;
     int dx[4]={-1,1,0,0};
     int dy[4]={0,0,1,-1};
    
    bool cycle_neighbour(int x,int y,vector<vector<char>>& grid,char curr,int parx,int pary)
       {
        
          for(int i=0;i<4;i++)
             {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx==parx && newy==pary) continue;
                if(newx>=0 && newy>=0 && newx<row&& newy<col && grid[newx][newy]==curr && visited[newx][newy])
                   {
                      return true;
                   }
            }
          return false;
        
    }

    void dfs(int x,int y,vector<vector<char>>& grid,char curr,int count,int parx,int pary)
    {
        if(ans) return;
        
        if(count>=4)
        {   if(cycle_neighbour(x,y,grid,curr,parx,pary))
              {
                ans=true;
                return;
              }
        }
        
        
        visited[x][y]=1;
        for(int i=0;i<4;i++)
           {
                int newx=x+dx[i];
                int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<row&& newy<col && grid[newx][newy]==curr && visited[newx][newy]==0)
                {
                    dfs(newx,newy,grid,curr,count+1,x,y);
                }
          }
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        row=grid.size();
        col=grid[0].size();
        
        visited.resize(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                 if(visited[i][j]==0)
                 {    ans=false;
                      int count=1;
                      dfs(i,j,grid,grid[i][j],count,-1,-1);
                      if(ans) return true;
                 }
                
                
            }
        }
        return false;
    }
};

-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------

 ------------------- Thoda Easy Method hai yeh  --------------------------------------
 -----------------------------------------------------------------------------------------------

 
class Solution {
public:
     int dx[4]={-1,1,0,0};
     int dy[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& grid,int x,int y,vector<vector<bool>>&visited,char ch,int px,int py)
    {
         visited[x][y]=true;
         int n=grid.size();
         int m=grid[0].size();
         for(int i=0;i<4;i++)
         {
                int newx=x+dx[i];
                int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<n&& newy<m && grid[newx][newy]==ch)
                {
                     if(!visited[newx][newy])
                     {
                         if(dfs(grid,newx,newy,visited,ch,x,y)) return true;
                     }
                     else if(newx !=px || newy!=py)  return true;
                    
                }
         }
        return false;
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++)
        {
             for(int j=0;j<col;j++)
             {
                  if(!visited[i][j])
                  {
                      char ch=grid[i][j];
                      if(dfs(grid,i,j,visited,ch,-1,-1)) return true;
                  }
                 
             }
            
        }
        return false;
    }
};