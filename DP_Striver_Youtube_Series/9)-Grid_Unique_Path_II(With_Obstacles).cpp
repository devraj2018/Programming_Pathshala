class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
     int row=mat.size();
     int col=mat[0].size();
     vector< vector< long long> > dp(row,vector<long long>(col,0));
     if(mat[0][0]==1) return 0;
    
     for(int i=0;i<row;i++)
       {
          for(int j=0;j<col;j++)
              {
                 if(i==0 && j==0) dp[i][j]=1;
                 else if(i== 0 && mat[i][j]==0) dp[i][j]=dp[i][j-1];
                 else if(j==0 &&  mat[i][j]==0) dp[i][j]=dp[i-1][j];
                 else if(mat[i][j]==0)  dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
               }
       
       }
      return dp[row-1][col-1];
        
    }
};