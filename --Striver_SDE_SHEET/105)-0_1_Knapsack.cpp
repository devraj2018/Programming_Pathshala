#include<bits/stdc++.h>

int helper(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>>&dp)
{
    if(n==0 || w==0) return 0;
     
    if(dp[n][w]!=-1) return dp[n][w];
    
    if(w>=weights[n-1]) return dp[n][w]=max(values[n-1]+helper(values,weights,n-1,w-weights[n-1],dp),helper(values,weights,n-1,w,dp));
    
    
    return dp[n][w]=helper(values,weights,n-1,w,dp);
      
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    return helper(values,weights,n,w,dp);
}