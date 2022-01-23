//   --------------- Tabulation  DP Code   -----------------------   //

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       for(int i=0;i<=n;i++)
          {
              for(int j=0;j<=W;j++)
                 {
                     if(i==0 || j==0) dp[i][j]=0;
                     else if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                     else if(wt[i-1]>j)dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][W];
       }
};

//   --------------- Memoized DP Code   -----------------------   //

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>>dp;
    int helper(int W,int wt[],int val[],int n)
    {
         if(n==0 || W==0) return 0;
         
         if(dp[n][W]!=-1) return dp[n][W];
         if(wt[n-1]<=W)   return dp[n][W]=max(val[n-1]+helper(W-wt[n-1],wt,val,n-1), helper(W,wt,val,n-1));
         else if(wt[n-1]>W)  return dp[n][W]=helper(W,wt,val,n-1);
         
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        dp.resize(n+1,vector<int>(W+1,-1));
        return helper(W,wt,val,n);
      
    }
};



// -----------------   Recursive Code   ---------------------     // 

class Solution
{   public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n==0 || W==0) return 0;
       
       if(wt[n-1]<=W) return max(val[n-1]+ knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       else return knapSack(W,wt,val,n-1);
      
    }
};