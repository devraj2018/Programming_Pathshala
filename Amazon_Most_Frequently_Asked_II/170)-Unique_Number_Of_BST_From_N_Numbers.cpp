class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                dp[i]+=dp[j-1]*dp[i-j];
            
        }
        return dp[n];
    }
};

/*
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        
        if(n==0 || n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+= numTrees(i-1)*numTrees(n-i);
        }
        return dp[n]=ans;
         
    }
    int numTrees(int n) {
        
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
*/