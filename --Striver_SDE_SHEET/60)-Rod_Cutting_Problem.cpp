int helper(vector<int>&price,int W,int n,vector<vector<int>>&dp)
{
     if(n<=0 || W<=0) return 0;
    
      if(dp[n][W]!=-1) return dp[n][W];
      int take=0;
      if(W-n>=0)
       take=price[n-1]+helper(price,W-n,n,dp);
     int dont_take=helper(price,W,n-1,dp);
    
      return dp[n][W]= max(take,dont_take);
    
}
int cutRod(vector<int> &price, int W)
{ vector<vector<int>>dp(price.size()+1,vector<int>(W+1,-1));
	return helper(price,W,price.size(),dp);
}
