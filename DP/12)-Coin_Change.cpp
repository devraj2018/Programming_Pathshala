class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {  int minn=INT_MAX;
              for(auto j:coins)
              {   if(i-j >= 0) minn=min(minn,dp[i-j]);
              }
          if(minn==INT_MAX) dp[i]=INT_MAX;
          else dp[i]=1+minn;
       }
       
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
        
        
    }

};
// --------------Memoization------------//
class Solution {
public:
    vector<int>dp;
    int helper(vector<int>& coins, int amount)
    {   
         if(amount<0) return INT_MAX;
         if(amount==0) return 0;
         
          if(dp[amount]!=-1) return dp[amount];
        
         int minn=INT_MAX;
         for(auto x: coins) minn=min(minn,helper(coins,amount-x));
         
         if(minn==INT_MAX) return dp[amount]=INT_MAX;
        
         return dp[amount]=1+minn;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans=helper(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
