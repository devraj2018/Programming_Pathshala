===========================================================================================
========================           Memoization       =====================================
===========================================================================================
int cutLogsHelper(int k, int n, vector<vector<int>> &lookUp)
{	
   
    if(n <= 1 || k <= 1)
    {
        return n;
    }

    if(lookUp[k][n] != -1)
    {
        return lookUp[k][n];
    }

    int ans = n;
	 
    for(int i=1; i <= n; i++)
    {
        int cur = max( cutLogsHelper(k-1, i-1, lookUp), cutLogsHelper(k, n-i, lookUp) );
        ans = min(ans, cur);
    }
	
    
    lookUp[k][n] = ans + 1;

    return lookUp[k][n];
}

int cutLogs(int k, int n)
{	
    
    vector<vector<int>> lookUp(k + 1, vector<int>(n + 1, -1));

    return cutLogsHelper(k, n, lookUp);
}


===========================================================================================
========================           Bottom UP DP O(N*K*K)       =====================================
===========================================================================================

int cutLogs(int k, int n)
{	
   
    int dp[k + 1][n + 1];

    for(int i=0; i <= k; i++)
    {
        for(int j=0; j <= n; j++)
        {
            dp[i][j] = j;
        }
    }
	
     
    for(int i=2; i <= k; i++)
    {	
        
        for(int j=2; j <= n; j++)
        {
            for(int t=1; t <= j; t++)
            {
                int cur = max( dp[i-1][t-1], dp[i][j-t] );
                dp[i][j] = min(dp[i][j], cur);
            }
            
            
            dp[i][j]++;
        }
    }
	
    
    return dp[k][n];
}


===========================================================================================
========================          O(N*K)   Optimised DP    =====================================
===========================================================================================

int cutLogs(int k, int n)
{    
    // Create an array dp
    vector<int> dp(n + 1);

    for(int i=0; i <= n; i++) dp[i] = i;
    for(int i=2; i <= k; i++)
     {    
         vector<int> dp2(n + 1);
         int t = 1;
         for(int j=1; j <= n; j++)
           {  while(t < j and max(dp[t - 1], dp2[j - t]) > max(dp[t], dp2[j - t - 1]))  t++;
              dp2[j] = 1 + max(dp[t - 1], dp2[j - t]);
           }
          dp = dp2;
    }
    
    return dp[n];
}