class Solution{

	public:
	int count_zero_till_index(int arr[],int i)
	{
	    int count=0;
	    for(int j=0;j<=i;j++)
	    {
	        if(arr[j]==0) count++;
	    }
	    return count;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));//First row is Automatically initialized to zero So no need to do it again
        
        int mod=1e9+7;
        
        for(int i=0;i<=n;i++) dp[i][0]= pow(2,count_zero_till_index(arr,i));   //For first column
        
         for(int i=1;i<=n;i++)
          {
             for(int j=1;j<=sum;j++)
               {
                if(arr[i-1]<=j) dp[i][j]=(dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod)%mod;
                else dp[i][j]=dp[i-1][j];
               }
          }
        return dp[n][sum];
   	}
	  
};