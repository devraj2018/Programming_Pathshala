class Solution {
public:
     int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
     bool is_valid;
      void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col,int x,int y)
      {
         if(grid1[x][y]==0) is_valid=false;
         grid2[x][y]=0;
         
         for(int i=0;i<4;i++)
            {
             
              int newx=x+dx[i];
              int newy=y+dy[i];
             
             if(newx>=0 && newy>=0 && newx<row && newy< col && grid2[newx][newy]==1)
                 dfs(grid1,grid2,row,col,newx,newy);
            }
      }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int row=grid1.size();
         int col=grid1[0].size();
        
         int ans=0;
        
         for(int i=0;i<row;i++)
          {
             for(int j=0;j<col;j++)
             {
                  if(grid2[i][j]==1)
                  {   is_valid=true;
                      dfs(grid1,grid2,row,col,i,j);
                      if(is_valid) ans++;
                  }
                 
             }
            
        }
        return ans;
        
    }
};