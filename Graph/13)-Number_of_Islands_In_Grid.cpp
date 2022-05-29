class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
         grid[x][y]='0';
         for(int i=0;i<4;i++)
           {  int newx=x+dx[i];
              int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]=='1') dfs(newx,newy,grid);
           }
        
    }
    int numIslands(vector<vector<char>>& grid) {
          n=grid.size();
          m=grid[0].size();
          int count=0;
          for(int i=0;i<n;i++)
           {
             for(int j=0;j<m;j++)
               {
                   if(grid[i][j]=='1')
                    {
                       count++;
                       dfs(i,j,grid);
                   }
               }
           }
        return count;
        
        
    }
};