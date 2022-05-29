// ------------------Tabulation --------------------//
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,INT_MAX));   
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {    
                 if(i==1 && j==1)   
                     dp[i][j]=grid[i-1][j-1];
                 else            
                     dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
             }
        }
        return dp[row][col];
        
    }
};
// ------------------Memoization --------------------//
class Solution {
public:
     vector<vector<int>>dp;
    int helper(int row,int col,vector<vector<int>>& grid)
     {    
         if(row<0 || col<0) return INT_MAX;
         
         if(row==0 && col==0) return grid[row][col];
        
         if(dp[row][col]!=-1) return dp[row][col];
         
         return dp[row][col]=grid[row][col]+ min(helper(row-1,col,grid),helper(row,col-1,grid));
     }
    int minPathSum(vector<vector<int>>& grid) {
          int row=grid.size();
          int col=grid[0].size();
          dp.resize(row,vector<int>(col,-1));
          return helper(row-1,col-1,grid);
     }
};
*/