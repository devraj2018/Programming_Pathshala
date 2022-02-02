//. LPS(X) == LCS( X, reverse(X))

class Solution {
public:
    int longestPalindromeSubseq(string X) {
        
        int n= X.length();
        string Y= X;
        reverse(Y.begin(),Y.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                 
                 if(X[i-1]==Y[j-1])
                     dp[i][j]=1+dp[i-1][j-1];
                 else
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 
            }
        }
        return dp[n][n];
        
        
        
    }
};