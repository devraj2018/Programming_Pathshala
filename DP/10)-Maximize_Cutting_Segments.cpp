class Solution
{
    public:
   vector<int>dp;
    int helper(int n,int x,int y,int z)
    {      if(n==0) return 0;
         
           if(dp[n]!=-1)  return dp[n];
         
           int maxx=INT_MIN;
           if(n-x>=0) maxx=max(maxx,helper(n-x,x,y,z));
           if(n-y>=0) maxx=max(maxx,helper(n-y,x,y,z));
           if(n-z>=0)maxx=max(maxx,helper(n-z,x,y,z));
          
           if(maxx==INT_MIN) return dp[n]= INT_MIN;
           
           return dp[n]=1+maxx;
           
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {   dp.resize(n+1,-1);
        int ans=helper(n,x,y,z);
        if(ans==INT_MIN) return 0;
        else return ans;
    }
};

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,0);
        
        
        for(int i=1;i<=n;i++)
           {
               int maxx=INT_MIN;
               if(i-x>=0) maxx=max(maxx,dp[i-x]);
               if(i-y>=0) maxx=max(maxx,dp[i-y]);
               if(i-z>=0) maxx=max(maxx,dp[i-z]);
               if(maxx!=INT_MIN) dp[i]=1+maxx;
               else dp[i]=INT_MIN;
         }
         if(dp[n]==INT_MIN) return 0;
         return dp[n];
    }
};