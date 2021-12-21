class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<int> dp(N,0);
         if(N==1) return 0;
         dp[0]=max(mat[0][0],mat[1][0]);
         dp[1]=max({mat[0][0],mat[0][1],mat[1][0],mat[1][1]});
         if(N==2) return dp[1];
         for(int i=2;i<N;i++)
         {  dp[i]=max(dp[i-1], dp[i-2]+max(mat[0][i],mat[1][i]));
          }
         return dp[N-1];
      }
};