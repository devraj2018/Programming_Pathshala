
// ------- Tabulation O(n)space Optimzed ------//
class Solution {
  public:
    long long int count(int S[], int m, int n) {
      vector<long long int>dp(n+1,0);
      dp[0]=1;
     
      for(int i=1;i<=m;i++)
        {
          for(int j=1;j<=n;j++)
           {
               if(j-S[i-1]>=0) dp[j] += dp[j-S[i-1]];
           }
      }
      return dp[n];
         
    }
};

// ------- Tabulation O(m*n)space ------//
class Solution {
  public:
   long long int count(int S[], int m, int n) {
       vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,0));
       for(int i=0;i<=m;i++) dp[i][0]=1;
     
       for(int i=1;i<=m;i++)
         {
           for(int j=1;j<=n;j++)
             {
                   dp[i][j]+= dp[i-1][j];

                   if(j-S[i-1]>=0)  dp[i][j] += dp[i][j-S[i-1]];
            }
        }
      return dp[m][n];
        
    }
};

//------------------------This approach is better than last one-------------------------- //
class Solution {
  public:
  vector<vector<long long int>> dp;
    long long int helper(int S[],int m,int n,int curr_I=0)
    { 
         if(n<0 || curr_I==m) return 0;
         if(n==0) return 1;
         
         if(dp[n][curr_I]!=-1) return dp[n][curr_I];
         
         long long int ans=0;
         // ------------- In this way we eliminate duplicate combinations   ----------- //
         ans+= helper(S,m,n,curr_I+1);     // If we leave that element, then all sets will not consider that ele
         
         ans+= helper(S,m,n-S[curr_I],curr_I);  // If we take that element, then awe can take that multiple times

        return dp[n][curr_I]=ans;
     }
    long long int count(int S[], int m, int n) {
      dp.resize(n+1,vector<long long int>(m+1,-1));
       
      return helper(S,m,n);
        
    }
};



class Solution {
  public:
  vector<vector<long long int>> dp;
    long long int helper(int S[],int m,int n,int curr_I=0)
    { 
         if(n<0) return 0;
         if(n==0) return 1;
         
         if(dp[n][curr_I]!=-1) return dp[n][curr_I];
         
         long long int ans=0;
         for(int i=curr_I;i<m;i++)
           {
             ans+= helper(S,m,n-S[i],i);
           }
          
          return dp[n][curr_I]=ans;
     }
    long long int count(int S[], int m, int n) {
      
      dp.resize(n+1,vector<long long int>(m+1,-1));
      return helper(S,m,n);
        
    }
};