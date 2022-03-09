class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(int x,int y,vector<vector<char>>& grid)
      {
           grid[x][y]='#';
         
           for(int i=0;i<4;i++)
            {
             int newx=x+dx[i];
             int newy=y+dy[i];
             
             if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]=='O')
                 dfs(newx,newy,grid);
         }
        
    }
    void solve(vector<vector<char>>& grid) {
        
         n=grid.size();
         m=grid[0].size();
         for(int i=0;i<n;i++)
         {
             if(grid[i][0]=='O') dfs(i,0,grid);
             if(grid[i][m-1]=='O') dfs(i,m-1,grid);
         }
         for(int j=1;j<m-1;j++)
          {
             if(grid[0][j]=='O') dfs(0,j,grid);
             if(grid[n-1][j]=='O') dfs(n-1,j,grid);
          }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='#')
                    grid[i][j]='O';
                else 
                    grid[i][j]='X';
            }
        }
        
        
    }
};