class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int helper(int n, int x, int y, int z, vector<int>&dp)
    {
         if(n==0) return 0;
         
         if(dp[n]!=-1) return dp[n];
         int ans=INT_MIN;
         
         if(n-x>=0) ans=max(ans,helper(n-x,x,y,z,dp));
         if(n-y>=0) ans=max(ans,helper(n-y,x,y,z,dp));
         if(n-z>=0) ans=max(ans,helper(n-z,x,y,z,dp));
         
         if(ans==INT_MIN)
         return dp[n]=INT_MIN;
         return dp[n]=1+ans;
            
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
         vector<int>dp(n+1,-1);
        int ans= helper(n,x,y,z,dp);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};