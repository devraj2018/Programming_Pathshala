==========================================================================================================
========================================= Bottom Up DP O(n)Time and O(1)Space ============================
==========================================================================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        
         int n=nums.size();
         
        
         if(n==1) return nums[0];
         if(n==2) return max(nums[0],nums[1]);
        
         int a=nums[0];
         int b=max(nums[0],nums[1]);
         int c;
        
         for(int i=2;i<n;i++)
         {
             c=max(nums[i]+a,b);
             a=b;
             b=c;
         }
        return c;
        
    }
};


==========================================================================================================
========================================= Bottom Up DP O(n)Time and O(n)Space ============================
==========================================================================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        
         int n=nums.size();
         vector<int>dp(n,0);
        
         if(n==1) return nums[0];
         if(n==2) return max(nums[0],nums[1]);
        
         dp[0]=nums[0];
         dp[1]=max(nums[0],nums[1]);
        
         for(int i=2;i<n;i++)
         {
             dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
         }
        return dp[n-1];
        
    }
};
========================================================================================================================
========================================= Recursion + Memoization ============================================================
========================================================================================================================


class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int n)
    {
         if(n<=0) return 0;
         
         if(dp[n]!=-1) return dp[n];
        
         int take=nums[n-1] + helper(nums,dp,n-2);
         int dont_take= helper(nums,dp,n-1);
        
         return dp[n]=max(take,dont_take);
         
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        
        return helper(nums,dp,n);
        
    }
};