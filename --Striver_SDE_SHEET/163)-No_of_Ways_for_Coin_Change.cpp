#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n+1,vector<long>(value+1,0));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=value;j++)
        {   
            if(i==0 && j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=1;
            else if(denominations[i-1]<=j)
                dp[i][j]=dp[i][j-denominations[i-1]]+dp[i-1][j];
            else 
                dp[i][j]=dp[i-1][j];
            
            
        }
    }
    return dp[n][value];
}