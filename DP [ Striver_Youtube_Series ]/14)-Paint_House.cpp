int Solution::solve(vector<vector<int> > &points) {
          int n=points.size();
          vector<vector<int>>dp(n+1,vector<int>(3,0));
    
        dp[1][0]=points[0][0];
        dp[1][1]=points[0][1];
        dp[1][2]=points[0][2];
        int premin= min(dp[1][0],min(dp[1][1],dp[1][2]));
     for(int i=2;i<=points.size();i++)
     {
         
         dp[i][0]=points[i-1][0]+min(dp[i-1][1],dp[i-1][2]);        // Dont consider dp[i-2][0] wala,bcz in that case
         dp[i][1]=points[i-1][1]+min(dp[i-1][0],dp[i-1][2]);       // We are skipping i-1th level which is wrong
         dp[i][2]=points[i-1][2]+min(dp[i-1][1],dp[i-1][0]);
         
         premin= min(dp[i][0],min(dp[i][1],dp[i][2]));
        
    }
    return premin;
}
