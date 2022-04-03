#include<bits/stdc++.h>
using namespace std;

int dp[101][1000001];
 //       ---------_Isko krna hai complete nhi hua h    //
int main()
{
     
    int n,sum;
    cin>>n>>sum;
    
    memset(dp,0,sizeof(dp));
    vector<int>coins(n);
    for(int i=0;i<n;i++)
     cin>>coins[i];
     int mod=1e9+7;
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=sum;j++)
         {
               if(i==0 && j==0) dp[i][j]=1;
               else if(i==0) dp[i][j]=0;
               else if(j==0) dp[i][j]=1;
               else if(coins[i-1]<=j)
               {
                   dp[i][j]=(dp[i-1][j-coins[i-1]]%mod +dp[i][j]%mod)%mod;
               }
               else dp[i][j]=dp[i-1][j]%mod;
               
               cout<<dp[i][j]<<" ";


         }
         cout<<endl;
     }
     cout<<endl;
     cout<<dp[n][sum];
    
  
}