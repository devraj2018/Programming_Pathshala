int Solution::candy(vector<int> &A) {

    int n=A.size();
    vector<int>dp(n,1);

    for(int i=1;i<n;i++)
    {
         if(A[i]>A[i-1] && dp[i]<=dp[i-1])
         {
             dp[i]=dp[i-1]+1;
         }
   }
   int ans=dp[n-1];
   for(int i=n-2;i>=0;i--)
    {
         if(A[i]>A[i+1] && dp[i]<=dp[i+1])    // This condition is important
         {
             dp[i]=dp[i+1]+1;
         }
         ans+=dp[i];
   }
    return ans;
}
