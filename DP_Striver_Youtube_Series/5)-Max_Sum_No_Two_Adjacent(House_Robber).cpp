//    Space Optimized Dp --> O(n) Time and O(1) Space
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
            c=max(a+nums[i],b);
            a=b;
            b=c;
            
         }
        return c;
        
        
    }
};

//    Tabulation Dp --> O(n) Time and O(n) Space

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
            
         }
        return dp[n-1];
    }
};
*/