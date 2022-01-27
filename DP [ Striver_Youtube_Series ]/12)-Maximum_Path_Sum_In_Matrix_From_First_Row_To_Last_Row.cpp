int getMaxPathSum(vector<vector<int>> &mat)
{
          int row=mat.size();
          int col=mat[0].size();
    
          vector<vector<int>>dp(row,vector<int>(col));
    
          if(col==1)
             {
                int ans=0;
                for(int i=0;i<row;i++) ans+=mat[i][0];
                return ans;
             }
    
          for(int i=0;i<col;i++) dp[0][i]=mat[0][i];
    
          for(int i=1;i<row;i++)
             {
                 for(int j=0;j<col;j++)
                       {
                             if(j==0) dp[i][j]=mat[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
                             else if(j==col-1) dp[i][j]=mat[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
                             else dp[i][j]=mat[i][j] + max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
             
                        }
               }
          int ans=INT_MIN;
          for(int i=0;i<col;i++) ans=max(ans,dp[row-1][i]);
    
          return ans;
}