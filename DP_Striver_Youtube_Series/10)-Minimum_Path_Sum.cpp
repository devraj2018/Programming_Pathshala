// Space Optimized Dp -- O(m * n)Time and O(n) Space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int row=grid.size();
         int col=grid[0].size();
        
         vector<int>dp(col,0);
         dp[0]=grid[0][0];
         for(int i=1;i<col;i++) dp[i]=dp[i-1]+grid[0][i];
            
         for(int i=1;i<row;i++)
            {  for(int j=0;j<col;j++)
                  {
                   if(j==0) dp[j]=dp[j]+grid[i][j];
                   else dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
                 }
            }
        return dp[col-1];
    
    }
};


// Tabulation   -- O(m * n)Time and O(m * n)Space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col));
        for(int i=0;i<row;i++)
          {
             for(int j=0;j<col;j++)
               {
                 if(i==0 && j==0) dp[i][j]=grid[i][j];
                 else if(i==0) dp[i][j]=dp[i][j-1]+grid[i][j];
                 else if(j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
                 else dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
               }
          }
        return dp[row-1][col-1];
     }
};