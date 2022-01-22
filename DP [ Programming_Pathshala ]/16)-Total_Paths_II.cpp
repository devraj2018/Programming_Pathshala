class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));  // Take one one extra to avoid many if else condition
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {    
                 if(i==1 && j==1 && grid[i-1][j-1]==0)  //  for first place
                     dp[i][j]=1;
                 else if(grid[i-1][j-1]==0)              // Only vallid through (i,j) if that block os empty block
                     dp[i][j]=dp[i-1][j]+dp[i][j-1];
             }
        }
        return dp[row][col];
    }
};
//--------------Memoization -----------------//

class Solution {      
public:
    vector<vector<int>>dp;
    int helper(int row,int col,vector<vector<int>>& grid)
    {    
         if(row<0 || col<0) return 0;
         
         if(row==0 && col==0 && grid[row][col]==0) return 1;
         if(dp[row][col]!=-1) return dp[row][col];
         
         if(grid[row][col]==1) return 0;
         
         return dp[row][col]=helper(row-1,col,grid)+helper(row,col-1,grid);
     }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        dp.resize(row,vector<int>(col,-1));
        return helper(row-1,col-1,grid);
        
    }
};
