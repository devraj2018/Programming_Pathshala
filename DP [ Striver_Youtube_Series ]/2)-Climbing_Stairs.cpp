class Solution {
public:
    int climbStairs(int n) {
        
         vector<int>dp(n+1);
          dp[0]=1;              // We can do it also in O(1) Space like we did in fibonaaci
          dp[1]=1;
          if(n==1) return 1;
          for(int i=2;i<=n;i++)
             dp[i]=dp[i-1]+dp[i-2];
        
         return dp[n];
        
    }
};
/*
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=helper(n-1,dp)+ helper(n-2,dp);
    }
    int climbStairs(int n) {
        
       vector<int>dp(n+1,-1);
        return helper(n,dp);
        
    }
};*/