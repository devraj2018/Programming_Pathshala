//Same as Unbounded Knapsack Just Different in intilaisation for first and second row

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        
         for(int j=1;j<=amount;j++)
             {
                dp[0][j]=INT_MAX-1;
            
                if(j%coins[0]==0) dp[1][j]= j/coins[0];
                else dp[1][j]=INT_MAX-1;
              }
        
           for(int i=2;i<=n;i++)
            {
               for(int j=1;j<=amount;j++)
                  {
                   if(coins[i-1]<=j) dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                   else dp[i][j]=dp[i-1][j];
                  }
             }
       
           if(dp[n][amount]==INT_MAX-1) return -1;
           return dp[n][amount];
    }
};