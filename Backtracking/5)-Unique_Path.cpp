class Solution {
public:
    int r,c;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int empty;
    int dfs(vector<vector<int>>& grid,int x,int y,int &curr_count)
    {   if(grid[x][y]==2)
         {  
            if(curr_count==empty+1) return 1;
            return 0;
         }
       
        grid[x][y]=-1;
        curr_count++;
        int moves=0; 
        for(int i=0;i<4;i++)
        {     int newx=x+dx[i];
              int newy=y+dy[i];
            
              if(newx>=0 && newx<r && newy>=0 && newy<c && ((grid[newx][newy]==0) ||(grid[newx][newy]==2)))
               {
                 moves+= dfs(grid,newx,newy,curr_count);
               }
        }
        grid[x][y]=0;    // Backtracking
        curr_count--;   // Backtracking
        return moves;
        
     }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        r=row;c=col;
        int x,y;
        int curr_count=0;
       
        int empty_count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                 if(grid[i][j]==1)
                 {
                     x=i;y=j;
                 }
                 else if(grid[i][j]==0)
                 {
                     empty_count++;
                 }
                
                
            }
        }
        empty=empty_count;
        return dfs(grid,x,y,curr_count);
        
    }
};