//  O(n)Time and O(1)Space
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1)return 1;
        
        int a=0,b=1,c;
        
        for(int i=2;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
        
        
    }
};

//  O(n)Time and O(n)Space // --   Memoization

class Solution {
public:
    vector<int>dp;
    int helper(int n)
    {
          if(n<=1) return n;
          
          if(dp[n]!=-1) return dp[n];

          return dp[n]=helper(n-1)+helper(n-2);

    }
    int fib(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};