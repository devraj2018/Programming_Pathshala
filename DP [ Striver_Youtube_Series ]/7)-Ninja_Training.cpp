// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// We can Space optimized  because we are using only previous 2 Levels

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    
        dp[1][0]=points[0][0];
        dp[1][1]=points[0][1];
        dp[1][2]=points[0][2];
        int premax= max(dp[1][0],max(dp[1][1],dp[1][2]));
     for(int i=2;i<=points.size();i++)
     {
         
         dp[i][0]=points[i-1][0]+max(dp[i-1][1],dp[i-1][2]);
         dp[i][1]=points[i-1][1]+max(dp[i-1][0],dp[i-1][2]);
         dp[i][2]=points[i-1][2]+max(dp[i-1][1],dp[i-1][0]);
         
         premax= max(dp[i][0],max(dp[i][1],dp[i][2]));
        
    }
    return premax;
}