#include <bits/stdc++.h>
using namespace std;
 
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    
    int n1= a.size();
    int n2=b.size();
    
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
             if(a[i-1]==b[j-1])  dp[i][j]=1+dp[i-1][j-1];
             else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             
         }
    }
    
    vector<int>res;
    
    int i=n1,j=n2;
    
    while(i>0 && j>0)
    {
         if(a[i-1]==b[j-1])
           { res.push_back(a[i-1]); i--;j--;
           }
         else if(dp[i-1][j]>dp[i][j-1]) i--;
         else j--;
        
    }
    
   reverse(res.begin(),res.end());
   return res; 

}

int main()
{
    vector<int>a,b;
    // INput a and b

    vector<int> result = longestCommonSubsequence(a, b);

     return 0;
}

