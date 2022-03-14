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

-------------------------------------------------------
-------------------------------------------------------

class Solution{   
public:
    int helper(int N, int arr[], int sum,vector<vector<int>>&dp){
        
        if(N==0 && sum==0) return 1;
        if(N==0) return 0;
        if(sum==0) return 1;
        
        if(dp[N][sum]!=-1) return dp[N][sum];
        
        if(sum>= arr[N-1])
          return dp[N][sum]= helper(N-1,arr,sum,dp) || helper(N-1,arr,sum-arr[N-1],dp);
        else
           return dp[N][sum]=helper(N-1,arr,sum,dp);
    }
    
    bool isSubsetSum(int N, int arr[], int sum){
        
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        
        int ans= helper(N,arr,sum,dp);
        
        if(ans) return true;
        return false;
        
    }
