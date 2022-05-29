long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
    dp[0]=1;                 // If 0 sum is required number of ways is 1.
    
    if(n==0) return dp[0];
    
    for( i=3;i<=n;i++) dp[i]+=dp[i-3];    // Used 3 different because i need distinct combinations
    for( i=5;i<=n;i++) dp[i]+=dp[i-5];   // If I used single loop then for n=8->I get 2 answer
    for(  i=10;i<=n;i++) dp[i]+=dp[i-10]; // Which is (3,5)pair and (5,3)pair and that count in repetations
    
    return dp[n];
   
    
    
}