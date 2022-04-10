class Solution {
public:
    int max_x,max_y,min_x,min_y;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m)
    {
           grid[x][y]=0;
           max_x=max(max_x,x);
           max_y=max(max_y,y);
           min_x=min(min_x,x);
           min_y=min(min_y,y);
           for(int i=0;i<4;i++)
             {  int newx=x+dx[i];
                int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
                    dfs(grid,newx,newy,n,m);
           }
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>>res;
        
        int row=land.size();
        int col=land[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                max_x=-1,max_y=-1,min_x=row+1,min_y=col+1;
                if(land[i][j]==1)
                {dfs(land,i,j,row,col);
                  res.push_back({min_x,min_y,max_x,max_y});
                }
                
            }
        }
        return res;
        
    }
};