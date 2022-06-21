#include<bits/stdc++.h>
int helper(string &s1,int n1,string &s2,int n2, vector<vector<int>>&dp)
{
    if(n1==0) return n2;
    if(n2==0) return n1;
    
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1-1]==s2[n2-1]) return dp[n1][n2]=helper(s1,n1-1,s2,n2-1,dp);
    
    return dp[n1][n2]= 1+min({helper(s1,n1-1,s2,n2,dp),helper(s1,n1,s2,n2-1,dp),helper(s1,n1-1,s2,n2-1,dp)});
      
}
int editDistance(string s1, string s2)
{
    int n1=s1.length();
        int n2=s2.length();
   vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    return helper(s1,n1,s2,n2,dp);
}