// This problem is just the modification of Longest Common Subsequence problem.
//The idea is to find the LCS(str, str)where str is the input string with the restriction
// that when both the characters are same, they shouldn’t be on the same index in the two strings. 

int Solution::anytwo(string A) {
string B=A;
int n=A.length();

vector<vector<int>>dp(n+1,vector<int>(n+1,0));

 for(int i=1;i<=n;i++)
 {
     for(int j=1;j<=n;j++)
     {
             

            if(A[i-1]==B[j-1] && i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

     }
 }
 return dp[n][n];

}