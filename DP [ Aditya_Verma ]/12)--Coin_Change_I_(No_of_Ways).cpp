class Solution {
public:
    
         int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>>dp(n+1,vector<int>(amount+1));
        
            for(int i=0;i<=n;i++)
              {
                 for(int j=0;j<=amount;j++)
                    {
                       if(i==0 && j==0) dp[i][j]=1;
                       else if(i==0) dp[i][j]=0;
                       else if(j==0) dp[i][j]=1;
                       else if(coins[i-1]<=j)
                           dp[i][j]= dp[i-1][j] + dp[i][j-coins[i-1]];
                       else
                          dp[i][j]=dp[i-1][j];
                    }
              }
           return dp[n][amount];
      }
};
/*
class Solution {
public:
    int helper(int n,vector<int>&coins,int amount, vector<vector<int>>&dp)
    {
           
           if(amount==0) return 1;
           if(n==0) return 0;
        
         
           if(dp[n][amount]!=-1) return dp[n][amount];
           if(coins[n-1]<=amount)
             {
               return dp[n][amount]=helper(n,coins,amount-coins[n-1],dp) +  helper(n-1,coins,amount,dp);
              }
           return dp[n][amount]=helper(n-1,coins,amount,dp);
      }
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
           vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
      
           return helper(n,coins,amount,dp);
        
    }
};
*/