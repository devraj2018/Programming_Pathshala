class Solution {
public:
    int row,col;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        
        grid[x][y]='0';
        
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(xx>=0 && yy>=0 && xx<row && yy<col && grid[xx][yy]=='1')
                dfs(xx,yy,grid);
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
      
        int count=0;
        row=grid.size();
        col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};