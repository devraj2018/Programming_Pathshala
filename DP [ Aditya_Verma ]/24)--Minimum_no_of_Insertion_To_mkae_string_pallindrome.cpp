class Solution {
public:
    int minInsertions(string s) {
        
        string srev=s;
        reverse(srev.begin(),srev.end());
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                 if(s[i-1]==srev[j-1])
                     dp[i][j]=1+dp[i-1][j-1];
                 else
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return n-dp[n][n];
        
    }
};