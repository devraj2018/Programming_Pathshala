int Solution::solve(vector<int> &A, int B) {
int n=A.size();
int W=B;
vector<vector<int>>dp(n+1,vector<int>(W+1,0));

 for(int i=0;i<=n;i++)
 {
     for(int j=0;j<=W;j++)
     {
          if(i==0 && j==0) dp[i][j]=1;
          else if(i==0) dp[i][j]=0;
          else if(j==0) dp[i][j]=1;
          else if(A[i-1]<=j) dp[i][j]= dp[i-1][j-A[i-1]] || dp[i-1][j];
          else dp[i][j]=dp[i-1][j];
  

     }
 }
 return dp[n][W];



}
