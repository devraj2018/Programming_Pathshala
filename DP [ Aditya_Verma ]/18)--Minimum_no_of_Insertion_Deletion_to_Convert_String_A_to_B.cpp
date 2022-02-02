//  ANother APPROACH IS 
// No. of Deletion in coversion from X -> LCS is ==>> Length of X - LCS 
// No of insertion to convert LCS -> Y is        ==>> Length of Y - LCS 

// Total is => L(X) + L(Y) - 2* LCS(length)

class Solution{
	 public:
     int minOperations(string X, string Y) 
    	{ 
	       int m= X.length();
	       int n= Y.length();
	     
	       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	      
	       for(int j=0;j<=n;j++) dp[0][j]=j;
	     
	       for(int i=0;i<=m;i++) dp[i][0]=i;
	      
           for(int i=1;i<=m;i++)
	         {
	           for(int j=1;j<=n;j++)
	               {
	                if(X[i-1]==Y[j-1])  dp[i][j]=dp[i-1][j-1];
	                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
	               }
	        }
	    return dp[m][n];
	} 
};
 
//  -------------       Memoized   DP -------------//
class Solution{
	 public:
	 int helper(string X,string Y,int m,int n,  vector<vector<int>>&dp)
	   {
	     if(m==0) return n;
	     if(n==0) return m;
	     
	     if(dp[m][n]!=-1) return dp[m][n];
	    
	     if(X[m-1]==Y[n-1]) return dp[m][n]=helper(X,Y,m-1,n-1,dp);
	       
	    
	     return dp[m][n]=1+min(helper(X,Y,m,n-1,dp), helper(X,Y,m-1,n,dp));
	  }
    int minOperations(string X, string Y) 
	  { 
	     int m= X.length();
	     int n= Y.length();
	     
	     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	     return helper(X,Y,m,n,dp);
	    
	 } 
};