// Time Complexity--   O(R * C * C * 9)     Space Complexity--  O(R * C * C)
int helper(int i,int j1,int j2,int r,int c, vector<vector<int>> &grid, vector<vector<vector<int>>>&dp)
{
          if(i== r-1)
            {
              if(j1==j2)
                  return grid[i][j1];
              else
                return grid[i][j1]+grid[i][j2];
            }
      
          if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    
         int max_ans=0;
         for(int first=-1;first<=1;first++)
           {                                                    // 9Possible move for at curr row ele
               for(int second=-1;second<=1;second++)
                   {
                     int row=i+1;
                     int col1=j1+ first;
                     int col2=j2+ second;
              
                     if(col1<0 || col2<0 || col1>=c || col2>=c) continue;
              
                     if(j1==j2)
                       {
                         max_ans=max(max_ans, grid[i][j1]+helper(row,col1,col2,r,c,grid,dp));
                       }
                    else
                      {
                         max_ans=max(max_ans, grid[i][j1]+grid[i][j2]+helper(row,col1,col2,r,c,grid,dp));
                      }
               
                  }
          }
     return dp[i][j1][j2]=max_ans;
    
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return helper(0,0,c-1,r,c,grid,dp);
}