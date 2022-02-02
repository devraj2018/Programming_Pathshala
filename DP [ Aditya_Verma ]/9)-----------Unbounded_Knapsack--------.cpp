
class Solution{             
public:
    vector<vector<int>>dp;
       
    int knapSack(int N, int W, int val[], int wt[])
    {
          dp.resize(N+1,vector<int>(W+1,0));

          for(int i=1;i<=N;i++)
          {
              for(int j=1;j<=W;j++)
              {
                      if(wt[i-1]<=j)
                        dp[i][j]=max(val[i-1]+ dp[i][j-wt[i-1]] , dp[i-1][j]);
                      else
                       dp[i][j]=dp[i-1][j];


              }
          }
          return dp[N][W];
    }
};



// ----------------------  Memoization  -------------------
class Solution{             
public:
      vector<vector<int>>dp;
      int helper(int N, int W, int val[], int wt[])
        {
          
           if(N==0 || W==0) return 0;
           
           if(dp[N][W]!=-1) return dp[N][W];
           
           
           if(wt[N-1]<=W)
           {
               return dp[N][W]= max(val[N-1]+ helper(N,W-wt[N-1],val,wt),helper(N-1,W,val,wt));
           }
          
           return dp[N][W]=helper(N-1,W,val,wt);
         
         
         
         
     }
    int knapSack(int N, int W, int val[], int wt[])
    {
          dp.resize(N+1,vector<int>(W+1,-1));
           return helper(N,W,val,wt);
    }
};