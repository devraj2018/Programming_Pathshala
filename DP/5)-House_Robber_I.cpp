class Solution {   // -------------Bottom Up------------//
public:
    int rob(vector<int>& nums) {
       
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
         
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
             dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
            
        }
        
        return dp[n-1];
    }
};


 


class Solution {          // -----  Top Down--------------//
public:
    int helper(vector<int>&nums,int n,vector<int>&dp)
    {
         if(n<=0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=max(nums[n-1]+helper(nums,n-2,dp),helper(nums,n-1,dp));
        
     }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,n,dp);
        
    }
};
 