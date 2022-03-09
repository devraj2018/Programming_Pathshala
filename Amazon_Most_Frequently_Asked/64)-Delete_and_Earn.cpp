https://leetcode.com/problems/delete-and-earn/

//     ---------------     Same as   House Robber     --------------------//
// -----   Just create sum array like every sum on number line----//
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>sum(10001,0),dp(10001,0);
        
        for(int i=0;i<n;i++)
            sum[nums[i]]+= nums[i];
        
        dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        
        for(int i=2;i<=10000;i++)
        {
            dp[i]= max(sum[i]+dp[i-2],dp[i-1]);
            
        }
        return dp[10000];
        
        
    }
};