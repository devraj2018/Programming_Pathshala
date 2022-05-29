class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        int ans=0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                 if(matrix[i-1][j-1]=='1')
                 {
                     dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                     
                 }
                 ans=max(ans,dp[i][j]);
           }
        }
        return ans*ans;
    }
};