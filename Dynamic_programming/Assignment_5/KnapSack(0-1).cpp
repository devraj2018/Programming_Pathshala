
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       for(int i=1;i<=n;i++)
         {
           for(int j=1;j<=W;j++)
              {
                 dp[i][j]=dp[i-1][j];
                 if(j-wt[i-1]>=0)
                 dp[i][j]=max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
              }
        }
       return dp[n][W];
       
    }
};

// -----------Memoization-------------------//

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>>dp;
    int helper(int W, int wt[], int val[], int &n,int curr_I=0)
    {
         if(W == 0 || curr_I==n) return 0;
         
        if(dp[curr_I][W]!=-1) return dp[curr_I][W];
         
         int take=INT_MIN,leave=INT_MIN;
         if(W-wt[curr_I]>=0)
           take=helper(W-wt[curr_I],wt,val,n,curr_I+1); // Taking
         
           leave=helper(W ,wt,val,n,curr_I+1); // Leaving
         
         if(take==INT_MIN && leave==INT_MIN) return dp[curr_I][W]=INT_MIN;
          
         return dp[curr_I][W]= max(leave,take+val[curr_I]);
           
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {    dp.resize(n+1,vector<int>(W+1,-1));
         int ans=helper(W,wt,val,n);
         if(ans==INT_MIN)
         return 0;
         return ans;
    }
};