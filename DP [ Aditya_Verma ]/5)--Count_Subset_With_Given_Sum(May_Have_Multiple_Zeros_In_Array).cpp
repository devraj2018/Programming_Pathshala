class Solution{

	public:
	int count_zero_till_that_index(int arr[],int i,int j)
	{
	    int count=0;
	    for(int start=i;start<=j;start++) if(arr[start]==0) count++;
	    return count;
	  }
	int perfectSum(int arr[], int n, int sum)
	{    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
          int mod=1e9+7;
          for(int i=0;i<=n;i++)
             {
                for(int j=0;j<=sum;j++)
                   {
                      if(i==0 && j==0) dp[i][j]=1;
                      else if(i==0) dp[i][j]=0;
                      else if(j==0) dp[i][j]=pow(2,count_zero_till_that_index(arr,0,i-1));
                      else if(j>=arr[i-1]) dp[i][j]= (dp[i-1][j]%mod+ dp[i-1][j-arr[i-1]]%mod)%mod;
                      else dp[i][j]=dp[i-1][j]%mod;
                  }
              }
         return dp[n][sum];
     }
	  
};