//  Space Optimized Dp With Tabulation
//  O(m * n) Time and [[  O(n)  ]] Space
class Solution {
public:
     int uniquePaths(int m, int n) {
        vector<int>dp(n,1),temp(n,1);
        if(m==1 || n==1) return 1;
         for(int i=1;i<m;i++)
             {  
               for(int j=1;j<n;j++)
                   temp[j]=temp[j-1]+dp[j];
           
              dp=temp;
            }
        return dp[n-1];
    }
};

//  Memoization -- O(m * n) Time and O(m * n) Space 
class Solution {
public:
    int helper(int m,int n,vector<vector<int>>&dp)
     {
           if(m==0 || n==0 ) return 1;
      
           if(dp[m][n]!=-1) return dp[m][n];
         
           return dp[m][n]=helper(m-1,n,dp)+helper(m,n-1,dp);
    
    
      }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp); 
        
    }
};

// Tabulation  -- O(m * n)Space and O(m * n) Time
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,1));
    if(m==1 || n==1) return 1;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    return dp[m-1][n-1];
}