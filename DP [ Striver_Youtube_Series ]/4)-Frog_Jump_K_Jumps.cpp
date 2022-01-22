//  https://atcoder.jp/contests/dp/tasks/dp_b   
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
     int n,k;
     cin>>n>>k;
     vector<int> arr(n);
     for(int i=0;i<n;i++)
     cin>>arr[i];
 
     vector<int>dp(n,INT_MAX);
     dp[0]=0;
     for(int i=1;i<n;i++)
     {
         for(int j=1 ;j<=k && (i-j)>=0 ;j++)
              {
                  dp[i]=min(dp[i], dp[i-j]+abs(arr[i]-arr[i-j]));
              }
    }
    cout<<dp[n-1]<<endl;
 
} 