______________________________________________________________________________________________________
__________________________________   1D Dp used ____________________________________________________________________
_____________________________________________________________________________________________
int Solution::minimumTotal(vector<vector<int> > &A) {
   
   int row=A.size();
  
   if(row==0) return 0;
   if(row==1) return A[0][0];

   vector<int>dp(row,0),temp(row,0);
    

   dp[0]=A[0][0];

   for(int i=1;i<row;i++)
   {
       for(int j=0;j<=i;j++)
       {
             if(j==0) temp[j]=dp[j]+A[i][j];
             else if(j==i) temp[j]=dp[j-1]+A[i][j];
             else temp[j]=A[i][j]+min(dp[j],dp[j-1]);



       }
       dp=temp;
   }
   int ans=INT_MAX;
   for(int j=0;j<row;j++)
   {
       ans=min(ans,dp[j]);
   }
   return ans;

}
______________________________________________________________________________________________________
__________________________________   2D Dp used ____________________________________________________________________
______________________________________________________________________________________________________


int Solution::minimumTotal(vector<vector<int> > &A) {
   
   int row=A.size();
  
   if(row==0) return 0;
   if(row==1) return A[0][0];

   vector<vector<int> > dp(row,vector<int>(row,0));

   dp[0][0]=A[0][0];

   for(int i=1;i<row;i++)
   {
       for(int j=0;j<=i;j++)
       {
             if(j==0) dp[i][j]=dp[i-1][j]+A[i][j];
             else if(j==i) dp[i][j]=dp[i-1][j-1]+A[i][j];
             else dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i-1][j-1]);



       }
   }
   int ans=INT_MAX;
   for(int j=0;j<row;j++)
   {
       ans=min(ans,dp[row-1][j]);
   }
   return ans;


}
