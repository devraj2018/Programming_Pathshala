#include<bits/stdc++.h>

//  +++    Other Greddy Approach when coins are like this  [1,2,5,10,20,50,100,500,1000]+++++++++++
int findMinimumCoins(int amount) 
{
     vector<int>coins={1,2,5,10,20,50,100,500,1000};
     int i=8;
     int count=0;
     while(i>=0 && amount>0)
     {
         if(coins[i]>amount)
             i--;
         else
         {
             while(amount-coins[i]>=0)
             {
                 count++;
                 amount-=coins[i];
             }
             
             
         }

     }
             return count;
}


========================================================================================================
=========+++++++++++    Memoizationn code +++++++++========================================
========================================================================================================
int helper(vector<int>&coins,int n,int amount,  vector<vector<int>>&dp)
{
     if(amount==0) return 0;
     if(n==0) return INT_MAX;
    
     if(dp[n][amount]!=-1) return dp[n][amount];
     int ans=INT_MAX;
     if(coins[n-1]<=amount)
     {
        ans=min(ans,1+helper(coins,n,amount-coins[n-1],dp));
     }
    
    ans=min(ans,helper(coins,n-1,amount,dp));
    return dp[n][amount]=ans;
    
    
    
}
int findMinimumCoins(int amount) 
{
     vector<int>coins={1,2,5,10,20,50,100,500,1000};
     int n=9;
    
    vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
    return helper(coins,n,amount,dp);
}
