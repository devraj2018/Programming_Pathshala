class Solution {
public:
    int minimumDeleteSum(string X, string Y) {
        
           int m= X.length();
	       int n= Y.length();
	     
	       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	      
	       for(int i=0;i<=m;i++)
	            {
	            for(int j=0;j<=n;j++)
	               {
                    
                     if(i==0 && j==0) dp[i][j]=0;
                     else if(i==0) dp[i][j]=dp[i][j-1]+Y[j-1];
                     else if(j==0) dp[i][j]=dp[i-1][j]+X[i-1];
                     else if(X[i-1]==Y[j-1])  dp[i][j]=dp[i-1][j-1];
	                 else dp[i][j]=min(X[i-1]+dp[i-1][j],Y[j-1]+dp[i][j-1]);
	               }
	         }
	    
       return dp[m][n];
        
        
    }
};