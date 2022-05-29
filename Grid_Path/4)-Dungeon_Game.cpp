class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row=dungeon.size();
         int col=dungeon[0].size();
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,INT_MAX));
        
        dp[row][col]=1;
        dp[row][col-1]=1;
        dp[row-1][col]=1;
        
        
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                 int minpow= min(dp[i][j+1],dp[i+1][j]) - dungeon[i][j];
                 if(minpow<=0)
                     dp[i][j]=1;
                 else
                     dp[i][j]=minpow;
              }
        }
        
        return dp[0][0];
    }
};