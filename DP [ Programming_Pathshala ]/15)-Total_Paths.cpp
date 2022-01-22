// -----------  Tabulation With most Space optimzed version -- O(n) space and O(m*n) Time //
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[j]+=dp[j-1];
        }
        return dp[n-1];
        
        
    }
};
// ------------Tabulation ------------ O(m * n) Space and O(m*n) Time//

class Solution {
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>>dp(m,vector<int>(n,0));
     
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};

// -------------Memoization ----------------O(m * n) Space +(Extra Recursive call stack)  and O(m*n) Time//

class Solution {
public:
    int helper(int m,int n)
    {  if(m==0 || n==0) return 1;
       if(dp[m][n]!=-1) return dp[m][n];
       return dp[m][n]=helper(m-1,n)+helper(m,n-1);
    }
    vector<vector<int>>dp;
    int uniquePaths(int m, int n) {
    dp.resize(m,vector<int>(n,-1));
    return helper(m-1,n-1);
   }
};
