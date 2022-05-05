class Solution{
   ///////// -----------------   If there are No Zero in Array -----------------///
	public:
	int perfectSum(int arr[], int n, int sum)
	{   int mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++)
           {
               for(int j=0;j<=sum;j++)
                 { 
                 if(i==0 && j==0 ) dp[i][j]=1;
                 else if(i==0) dp[i][j]=0;
                 else if(j==0) dp[i][j]=1;
                 else if(arr[i-1]<=j) dp[i][j]= (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                 else dp[i][j]=dp[i-1][j];
                }
            }
        return dp[n][sum];
	}
	  
};

---------------------------------   If there are Zeros in Array -----------------
class Solution{

	public:
	int count_zero_till_that_index(int arr[],int i)
	{
	    int count=0;
	    for(int j=0;j<i;j++)
	    {
	        if(arr[j]==0) count++;
	    }
	    return count;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        int m=1e9+7;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                 if(i==0 && j==0) dp[i][j]=1;
                 else if(i==0) dp[i][j]=0;
                 else if(j==0) dp[i][j]=pow(2,count_zero_till_that_index(arr,i));
                 else if(j>=arr[i-1]) dp[i][j]=(dp[i-1][j-arr[i-1]]%m+dp[i-1][j]%m)%m;
                 else dp[i][j]=dp[i-1][j]%m;
                
                
            }
        }
        
        return dp[n][sum];
        
	}
	  
};