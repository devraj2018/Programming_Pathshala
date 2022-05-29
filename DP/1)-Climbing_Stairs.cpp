class Solution {  // Recursive O(n)Space + Extra call stack +Top Down DP
public:
    vector<int>dp;
    int helper(int n)
    {   if(n<=0) return 0;
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=helper(n-1)+helper(n-2);
   }
    int climbStairs(int n) {
       dp.resize(n+1,-1);
       return helper(n);
    }
};


class Solution {  //Iterative O(n)Space + Bottom Up DP
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        if(n==0) return 0;
        if(n==1) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

class Solution {  //Iterative O(1)Space + Bottom Up DP
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a=1;
        int b=1;
        int c;
        for(int i=2;i<=n;i++) 
        {
            c=a+b;
            a=b;b=c;
        }
        return c;
    }
};