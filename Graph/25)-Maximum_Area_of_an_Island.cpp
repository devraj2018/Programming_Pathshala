class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int row,int col,int x,int y,int &ans)
      {
          grid[x][y]=0;
          ans++;
          for(int i=0;i<4;i++)
              {
                 int newx=x+dx[i];
                 int newy=y+dy[i];
                 if(newx>=0 && newy>=0 && newx<row && newy< col && grid[newx][newy]==1)
                     dfs(grid,row,col,newx,newy,ans);
              }
      }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int row=grid.size();
         int col=grid[0].size();
        
         int maxx=0;
         
        
         for(int i=0;i<row;i++)
           {
              for(int j=0;j<col;j++)
                {
                   if(grid[i][j]==1)
                     {   int ans=0;
                          dfs(grid,row,col,i,j,ans);
                          maxx=max(maxx,ans);
                     }
                 }
           }
        return maxx;
    }
};