int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
        
      
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {   for (int j = 1; j <= n; j++)
          {
             if (i == j)  dp[i][j] = 0;
             else  dp[i][j] = 1e9;
          }
    }
   
    
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dp[u][v] = w;
    }

   
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][k] != 1e9 && dp[k][j] != 1e9)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

   
    return dp[src][dest];
}